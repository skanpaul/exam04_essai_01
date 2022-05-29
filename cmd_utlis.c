/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:47:47 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 07:34:22 by sorakann         ###   ########.fr       */
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
void add_cmd_to_args(char **array, char *new_arg)
{
	int		i;
	int		size_array;
	char	**new_array;
	
	new_array = NULL;
	if (!array)
	{
		array = (char **)malloc(sizeof(char *) * 2);
		array[0] = new_arg;
		array[1] = NULL;
	}
	else
	{
		size_array = get_size_array(array);
		new_array = (char **)malloc(sizeof(char *) * (size_array + 2));
		
		new_array[size_array] = new_arg;
		new_array[size_array + 1] = NULL;
		

		//free old array
	}
}
/* ************************************************************************** */
void copy_array(char **src_array, char **dst_array)
{
	int i;
	
	i = 0;
	while (src_array[i])
	{
		dst_array[i] = src_array[i];
		i++;
	}
	dst_array[i] = NULL;
}
/* ************************************************************************** */
int get_size_array(char **array)
{
	int i;

	i = 0;
	if (!array)
		return(0);
	
	while (array[i])
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