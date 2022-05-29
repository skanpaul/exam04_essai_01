/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:09:07 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 11:41:15 by ski              ###   ########.fr       */
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

	if (argc < 2)
		return (print_error(MSG_ERR_ARGC));
		
	initialisation(&p, argc, argv, envp);	
	
	p.seg_start = 1;
	p.seg_end = get_seg_end(&p);	
	run_segment(&p);	
	
	clean_program(&p);
	
	return(0);
}

/* ************************************************************************** */
void print_start_child(char **array)
{	
	print_error("\n");
	print_error("---------------------------------------------\n");
	print_error("Start-CHILD\n");
	print_array(array);
	print_error("---------------------------------------------\n");
}

/* ************************************************************************** */
void print_end_parent(void)
{	
	print_error("\n");
	print_error("---------------------------------------------\n");
	print_error("End-PARENT\n");
	print_error("---------------------------------------------\n");
	print_error("\n");
}

/* ************************************************************************** */