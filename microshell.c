/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:09:07 by ski               #+#    #+#             */
/*   Updated: 2022/05/30 14:43:54 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// EXEMPLE:
// 1) $>./microshell /bin/ls
// 2) $>./microshell /bin/ls "|" /usr/bin/grep microshell 
// 3) $>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
int main (int argc, char **argv, char **envp)
{
	t_param	p;

	initialisation(&p, argc, argv, envp);

	p.seg_start = 1;
	set_next_seg_end(&p);
		
	while (p.seg_start < p.argc)
		run_segment(&p);

	clean_program(&p);
	return(0);
}

/* ************************************************************************** */
void initialisation(t_param *p, int argc, char **argv, char **envp)
{
	// ---------------------
	p->stdin_origin = dup(STDIN_FILENO);
	p->stdout_origin = dup(STDOUT_FILENO);
	p->stderr_origin = dup(STDERR_FILENO);
	// ---------------------
	p->argc = argc;
	p->argv = argv;
	p->envp = envp;
	// ---------------------
	p->seg_start = 0;
	p->seg_end = 0;
	// ---------------------
	p->path = NULL;
	p->cmd = NULL;
	p->array = NULL;
	// ---------------------
}

/* ************************************************************************** */
void clean_program(t_param *p)
{
	free_array(&p->array);
	dup2(p->stdin_origin, STDIN_FILENO);
	dup2(p->stdout_origin, STDOUT_FILENO);
}

/* ************************************************************************** */
// void print_start_child(char **array)
// {	
// 	print_error("\n");
// 	print_error("---------------------------------------------\n");
// 	print_error("Start-CHILD\n");
// 	print_array(array);
// 	print_error("---------------------------------------------\n");
// }

// /* ************************************************************************** */
// void print_end_parent(void)
// {	
// 	print_error("\n");
// 	print_error("---------------------------------------------\n");
// 	print_error("End-PARENT\n");
// 	print_error("---------------------------------------------\n");
// 	print_error("\n");
// }

// /* ************************************************************************** */