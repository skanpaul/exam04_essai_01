/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:51:23 by sorakann          #+#    #+#             */
/*   Updated: 2022/05/29 21:14:44 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
void create_pipe(t_param *p)
{
	if(pipe(p->fd_pipe) == -1)
		exit_syscal_err(p, errno);

	p->w_pipe = p->fd_pipe[1];
	p->r_pipe = p->fd_pipe[0];	
}

/* ************************************************************************** */
void set_redirection_out(t_param *p)
{
	char *next_token;

	next_token = p->argv[p->seg_end + 1];	
	if (does_word_match(next_token, "|"))
		dup2(p->w_pipe, STDOUT_FILENO);
	else
		dup2(p->stdout_origin, STDOUT_FILENO);
}

/* ************************************************************************** */
void set_redirection_in(t_param *p)
{
	char *next_token;

	next_token = p->argv[p->seg_end + 1];	
	if (does_word_match(next_token, "|"))
		dup2(p->r_pipe, STDIN_FILENO);
	else
		dup2(p->stdin_origin, STDIN_FILENO);
}

/* ************************************************************************** */