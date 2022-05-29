/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:09:07 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 10:15:34 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// EXEMPLE:
// 1) $>./microshell /bin/ls
// 2) $>./microshell /bin/ls "|" /usr/bin/grep microshell 
// 3) $>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
static void print_end_parent(void);
static void print_start_child(char **array);

/* ************************************************************************** */
int main (int argc, char **argv, char **envp)
{
	int		fc;
	int		status;
	t_param	p;

	initialisation(&p);
	// --------------------------------------------------	
	if (argc < 2)
		return (print_error(MSG_ERR_ARGC));

	fc = fork();
	if (is_fork_error(fc))
		return (print_error(MSG_ERR_SYSCALL));		
	// --------------------------------------------------
	if (is_fork_child(fc))
	{
		p.path = argv[1]; // a effacer
		p.cmd = extract_cmd(p.path);
		p.array = add_string_to_array(p.array, p.cmd);

		print_start_child(p.array);
		execve(p.path, p.array, envp);		
		print_error("!!! Failure-CHILD !!!\n");
		exit(EXIT_FAILURE);
	}
	// --------------------------------------------------
	if (is_fork_parent(fc))
	{		
		if(waitpid(fc, &status, 0) == -1)
			return (print_error(MSG_ERR_SYSCALL));
		print_end_parent();
	}
	// --------------------------------------------------
	clean_program(&p);
	return(0);
}

/* ************************************************************************** */
static void print_start_child(char **array)
{	
	print_error("\n");
	print_error("---------------------------------------------\n");
	print_error("Start-CHILD\n");
	print_error("---------------------------------------------\n");
}

/* ************************************************************************** */
static void print_end_parent(void)
{	
	print_error("\n");
	print_error("---------------------------------------------\n");
	print_error("End-PARENT\n");
	print_error("---------------------------------------------\n");
	print_error("\n");
}

/* ************************************************************************** */