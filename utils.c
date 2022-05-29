/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:23:09 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 11:48:32 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
void initialisation(t_param *p, int argc, char **argv, char **envp)
{
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

void clean_program(t_param *p)
{
	(void)p;
	free_array(&p->array);
}

/* ************************************************************************** */
bool does_word_match(char *src, char *hard_str)
{
	if( strncmp(src, hard_str, ft_strlen(hard_str) + 1) == 0)
		return (true);
	return (false);
}

/* ************************************************************************** */
int get_seg_end(t_param *p)
{
	int i;

	i = p->seg_start;
	while (i < p->argc && !does_word_match(p->argv[i], "|")
			&& !does_word_match(p->argv[i], ";"))
	{
		i++;
	}
	return (i - 1);	
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