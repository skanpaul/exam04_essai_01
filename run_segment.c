/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:52:28 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 21:24:40 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

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
		
		execve(p->path, p->array, p->envp);
		print_err_execve(p);
		exit(EXIT_FAILURE);
	}
	// --------------------------------------------------
	close(p->w_pipe);
	set_redirection_in(p);
	close(p->r_pipe);
	
	if(waitpid(fk, &status, 0) == -1)
		exit_syscal_err(p, errno);
	
	free_array(&p->array);	
	set_next_seg_start(p);
	set_next_seg_end(p);	
	// --------------------------------------------------
	return (0);
}

/* ************************************************************************** */