/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:09:07 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 07:17:14 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// EXEMPLE:
// 1) $>./microshell /bin/ls
// 2) $>./microshell /bin/ls "|" /usr/bin/grep microshell 
// 3) $>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
void initialisation(t_param *p)
{
	p->path_and_cmd = NULL;
	p->cmd = NULL;
	p->cmd_and_args = NULL;
}

/* ************************************************************************** */
int main (int argc, char **argv, char **envp)
{
	t_param	p;

	(void)argc;
	(void)argv;
	(void)envp;
	initialisation(&p);

	if (argc < 2)
		return (print_error(MSG_ERR_ARGC));

	p.path_and_cmd = argv[1];	

	p.fork_code = fork();
	// --------------------------------------------------
	if (is_fork_error(p.fork_code))
		return (print_error(MSG_ERR_SYSCALL));
	// --------------------------------------------------
	if (is_fork_child(p.fork_code))
	{
		print_error("Start-CHILD\n");

		p.cmd = extract_cmd(p.path_and_cmd);		
		// execve(p.path_and_cmd, p.cmd, envp);
		
		print_error("Failure-CHILD\n");
		exit(EXIT_FAILURE);
	}
	// --------------------------------------------------
	if (is_fork_parent(p.fork_code))
	{
		p.pid_child = p.fork_code;
		
		if(waitpid(p.pid_child, &p.status_child, 0) == -1)
			return (print_error(MSG_ERR_SYSCALL));
		ft_free(&p.cmd);
		print_error("End-PARENT\n");
	}
	// --------------------------------------------------
	return(0);
}





/* ************************************************************************** */