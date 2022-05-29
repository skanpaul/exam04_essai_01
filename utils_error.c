/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:10:22 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 15:58:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
int print_error(char *msg_error)
{
	write(STDERR_FILENO, msg_error, ft_strlen(msg_error));
	return (1);
}

/* ************************************************************************** */
void print_err_execve(t_param *p)
{	
	print_error(MSG_ERR_EXECVE);
	print_error(p->path);
	print_error("\n");
}


/* ************************************************************************** */
void print_err_chdir(t_param *p)
{	
	(void)p;
	// print_error(MSG_ERR_EXECVE);
	// print_error(p->path);
	// print_error("\n");
}

/* ************************************************************************** */
int exit_syscal_err(t_param *p, int err_code)
{
	print_error(MSG_ERR_SYSCALL);
	clean_program(p);
	exit(err_code);
}

/* ************************************************************************** */