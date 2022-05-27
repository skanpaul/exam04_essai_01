/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:47:47 by ski               #+#    #+#             */
/*   Updated: 2022/05/27 15:11:42 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
char *extract_cmd(char *path_and_cmd)
{
	int len;
	int i;
	char *cmd;

	cmd = NULL;	
	len = ft_strlen(path_and_cmd);

	if (path_and_cmd[len] == '/')
		return NULL;	

	i = len;
	while (path_and_cmd[i] != '/')
		i--;

	cmd = ft_strdup(&path_and_cmd[i + 1]);

	return cmd;	
}

/* ************************************************************************** */
// [ new_arg ] HAS TO BE malloc before entering this function 
void add_cmd_to_args(char **cmd_and_args, char *new_arg)
{
	if (!cmd_and_args)
	{
		cmd_and_args = (char **)malloc(sizeof(char *) * 2);
		cmd_and_args[0] = new_arg;
		cmd_and_args[1] = NULL;
	}
	else
	{
		
	}
}
/* ************************************************************************** */
int get_size_array(char **cmd_and_args)
{
	int i;

	i = 0;
	if (!cmd_and_args)
		return(0);
	
	while (cmd_and_args[i])
		i++;
	return (i);
}

/* ************************************************************************** */
void free_array(char ***array)
{
	int i;

	if (!(*array))
		return ;
	
	i = 0;
	while ((*array)[i])
	{
		ft_free(&(*array)[i]);
		i++;
	}
	
	
}

/* ************************************************************************** */