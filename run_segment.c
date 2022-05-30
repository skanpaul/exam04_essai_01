/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:52:28 by ski               #+#    #+#             */
/*   Updated: 2022/05/30 16:38:45 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
static void cd_builtin(t_param *p);

/* ************************************************************************** */
int run_segment(t_param *p)
{
	int		fk;
	int		status;
	
	p->path = p->argv[p->seg_start];
	
	p->cmd = extract_cmd(p->path);
	build_array(p);
	ft_free(&p->cmd);		
	
	create_pipe(p);
	
	// --------------------------------------------------	
	fk = fork();
	if (is_fork_error(fk))
		exit_syscal_err(p, errno);		
	// --------------------------------------------------
	if (is_fork_child(fk))
	{
		close(p->r_pipe);
		set_redirection_out(p);
		close(p->w_pipe);

		if(!does_word_match(p->array[0], "cd"))
		{
			execve(p->path, p->array, p->envp);		
			print_err_execve(p);
			exit(EXIT_FAILURE);	
		}
		exit(EXIT_SUCCESS);
	}
	// --------------------------------------------------
	close(p->w_pipe);
	set_redirection_in(p);
	close(p->r_pipe);

	if(does_word_match(p->array[0], "cd"))
		cd_builtin(p);	
	
	if(waitpid(fk, &status, 0) == -1)
		exit_syscal_err(p, errno);
	
	free_array(&p->array);	
	set_next_seg_start(p);
	set_next_seg_end(p);	
	// --------------------------------------------------
	return (0);
}

/* ************************************************************************** */
static void cd_builtin(t_param *p)
{
	if (!(p->array[1] && !p->array[2]))
		print_error(MSG_ERR_CD_ARG);
	if(chdir(p->array[1]) == -1)
		print_err_chdir(p);			
}
