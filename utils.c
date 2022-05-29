/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:23:09 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 14:15:06 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
void set_next_seg_start(t_param *p)
{
	if (does_word_match(p->argv[p->seg_end + 1], "|")
		|| does_word_match(p->argv[p->seg_end + 1], ";"))
	{
		p->seg_start = p->seg_end + 2;
	}
	else
	{
		p->seg_start = p->argc;		
	}	
}


/* ************************************************************************** */
void set_next_seg_end(t_param *p)
{
	int i;

	if (p->seg_start == p->argc)
	{
		p->seg_end = p->argc;
		return ;
	}

	i = p->seg_start;
	while (i < p->argc && !does_word_match(p->argv[i], "|")
			&& !does_word_match(p->argv[i], ";"))
	{
		i++;
	}
	p->seg_end = i - 1;	
}

/* ************************************************************************** */
bool does_word_match(char *src, char *hard_str)
{
	if (!src)
		return (false);
	if( strncmp(src, hard_str, ft_strlen(hard_str) + 1) == 0)
		return (true);
	return (false);
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
	while (path[i] != '/' && i != 0)
		i--;

	cmd = ft_strdup(&path[i + 1]);

	return cmd;	
}

/* ************************************************************************** */