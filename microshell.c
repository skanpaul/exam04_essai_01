/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:09:07 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 10:01:16 by ski              ###   ########.fr       */
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
	int		fc;
	int		status;
	t_param	p;

	initialisation(&p, argc, argv, envp);
	// --------------------------------------------------	
	if (argc < 2)
		return (print_error(MSG_ERR_ARGC));

	p.path = argv[1]; // a effacer
	
	fc = fork();	
	// --------------------------------------------------
	if (is_fork_error(fc))
		return (print_error(MSG_ERR_SYSCALL));
		
	// --------------------------------------------------
	if (is_fork_child(fc))
	{
		print_error("\n---------------------------------------------\n");
		print_error("Start-CHILD\n");
		p.cmd = extract_cmd(p.path);
		print_error(p.cmd);
		p.array = add_cmd_to_array(p.array, p.cmd);				
		execve(p.path, p.array, envp);		
		print_error("!!! Failure-CHILD !!!\n");
		exit(EXIT_FAILURE);
	}
	// --------------------------------------------------
	if (is_fork_parent(fc))
	{		
		if(waitpid(fc, &status, 0) == -1)
			return (print_error(MSG_ERR_SYSCALL));
		print_error("---------------------------------------------\n");
		print_error("End-PARENT\n\n");
	}
	// --------------------------------------------------
	clean_program(&p);
	return(0);
}

/* ************************************************************************** */