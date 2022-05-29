/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:52:28 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 16:33:35 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
static void set_redirection(t_param *p);
static void manage_pipe(t_param *p);

/* ************************************************************************** */
int run_segment(t_param *p)
{
	int		fc;
	int		status;
	
	p->path = p->argv[p->seg_start];
	p->cmd = extract_cmd(p->path);
	build_array(p);
	ft_free(&p->cmd);
	
	manage_pipe(p);
	set_redirection(p);
	
	// --------------------------------------------------	
	fc = fork();
	if (is_fork_error(fc))
		exit_syscal_err(p, errno);		
	// --------------------------------------------------
	if (is_fork_child(fc))
	{
		close(p->r_pipe);
		execve(p->path, p->array, p->envp);
		close(p->w_pipe);
		print_err_execve(p);
		exit(EXIT_FAILURE);
	}
	// --------------------------------------------------
	if(waitpid(fc, &status, 0) == -1)
		exit_syscal_err(p, errno);
	close(p->w_pipe);
	
	free_array(&p->array);	
	set_next_seg_start(p);
	set_next_seg_end(p);	
	// --------------------------------------------------
	return (0);
}

/* ************************************************************************** */
static void manage_pipe(t_param *p)
{
	char *next_token;
	
	next_token = p->argv[p->seg_end + 1];
	
	if (does_word_match(next_token, "|"))
	{
		if(pipe(p->fd_pipe) == -1)
			exit_syscal_err(p, errno);

		p->w_pipe = p->fd_pipe[1];
		p->r_pipe = p->fd_pipe[0];	
	}		
}

/* ************************************************************************** */
static void set_redirection(t_param *p)
{
	char *next_token;
	char *prev_token;
	
	// ----------------------------------------
	next_token = p->argv[p->seg_end + 1];	
	if (does_word_match(next_token, "|"))
		dup2(p->w_pipe, STDOUT_FILENO);
	else
		dup2(p->stdout_origin, STDOUT_FILENO);
	// ----------------------------------------
	prev_token = p->argv[p->seg_start - 1]; 
	if (does_word_match(prev_token, "|"))
		dup2(p->r_pipe, STDIN_FILENO);
	else
		dup2(p->stdin_origin, STDIN_FILENO);
}

/* ************************************************************************** */