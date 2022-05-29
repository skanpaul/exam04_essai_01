/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:23:09 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 10:03:38 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
// void initialisation(t_param *p, int argc, char **argv, char **envp)
void initialisation(t_param *p)
{
	// ---------------------
	// p->argc = argc;
	// p->argv = argv;
	// p->envp = envp;
	// ---------------------
	p->path = NULL;
	p->cmd = NULL;
	p->array = NULL;
}

/* ************************************************************************** */
void clean_program(t_param *p)
{
	(void)p;
	free_array(&p->array);
}

/* ************************************************************************** */
char *extract_cmd(char *path)
{
	int len;
	int i;
	char *cmd;

	cmd = NULL;	
	len = ft_strlen(path);

	if (path[len] == '/')
		return NULL;	

	i = len;
	while (path[i] != '/')
		i--;

	cmd = ft_strdup(&path[i + 1]);

	return cmd;	
}

/* ************************************************************************** */