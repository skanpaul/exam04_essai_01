/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:52:28 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 10:54:54 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
void run_segment(t_param *p)
{
	int		fc;
	int		status;
	
	// --------------------------------------------------	
		fc = fork();
	if (is_fork_error(fc))
		return (print_error(MSG_ERR_SYSCALL));		
	// --------------------------------------------------
	if (is_fork_child(fc))
	{
		p.path = argv[1]; // a effacer
		p.cmd = extract_cmd(p.path);
		p.array = add_string_to_array(p.array, p.cmd);
		ft_free(&p.cmd);

		print_start_child(p.array);
		execve(p.path, p.array, envp);
		print_err_execve(&p);
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




	
}

