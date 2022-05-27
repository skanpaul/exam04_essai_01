/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:09:07 by ski               #+#    #+#             */
/*   Updated: 2022/05/27 14:58:31 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// EXEMPLE:\
// 1) $>./microshell /bin/ls
// 2) $>./microshell /bin/ls "|" /usr/bin/grep microshell 
// 3) $>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
int main (int argc, char **argv, char **envp)
{
	int fork_code;
	int pid_child;
	int status_child;
	char *path_and_cmd;
	char *cmd;
	char **cmd_and_args;
	
	cmd_and_args = NULL;
	path_and_cmd = NULL;
	cmd = NULL;
	(void)argc;
	(void)argv;
	(void)envp;

	if (argc < 2)
		return (print_error(MSG_ERR_ARGC));

	path_and_cmd = argv[1];	

	fork_code = fork();
	// --------------------------------------------------
	if (is_fork_error(fork_code))
		return (print_error(MSG_ERR_SYSCALL));
	// --------------------------------------------------
	if (is_fork_child(fork_code))
	{
		print_error("Start-CHILD\n");

		cmd = extract_cmd(path_and_cmd);		
		execve(path_and_cmd, cmd, envp);
		
		print_error("Failure-CHILD\n");
		exit(EXIT_FAILURE);
	}
	// --------------------------------------------------
	if (is_fork_parent(fork_code))
	{
		pid_child = fork_code;
		
		if(waitpid(pid_child, &status_child, 0) == -1)
			return (print_error(MSG_ERR_SYSCALL));
		ft_free(&cmd);
		print_error("End-PARENT\n");
	}
	// --------------------------------------------------
	return(0);
}





/* ************************************************************************** */