/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:52:28 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 11:39:12 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
int run_segment(t_param *p)
{
	int		fc;
	int		status;
	

	p->path = p->argv[p->seg_start];
	p->cmd = extract_cmd(p->path);
	build_array(p);
	
	// --------------------------------------------------	
		fc = fork();
	if (is_fork_error(fc))
		return (print_error(MSG_ERR_SYSCALL));		
	// --------------------------------------------------
	if (is_fork_child(fc))
	{
		print_start_child(p->array);
		execve(p->path, p->array, p->envp);
		print_err_execve(p);
		exit(EXIT_FAILURE);
	}
	// --------------------------------------------------

	if(waitpid(fc, &status, 0) == -1)
		return (print_error(MSG_ERR_SYSCALL));

	free_array(&p->array);	
		
	print_end_parent();
	
	// --------------------------------------------------
	return (0);
}

