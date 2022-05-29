/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:47:47 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 09:44:22 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
static void	copy_array(char **src_array, char **dst_array);

/* ************************************************************************** */
// [ new_arg ] will be mallocated
char **add_cmd_to_array(char **array, char *new_arg)
{
	int		size_array;
	char	**new_array;
	
	new_array = NULL;
	if (!array)
	{
		array = (char **)malloc(sizeof(char *) * 2);
		array[0] = ft_strdup(new_arg);
		array[1] = NULL;
		return (array);
	}

	size_array = get_size_array(array);
	new_array = (char **)malloc(sizeof(char *) * (size_array + 2));
	copy_array(array, new_array);
	new_array[size_array] = ft_strdup(new_arg);
	new_array[size_array + 1] = NULL;
	free_array(&array);		
	return (new_array);
}
/* ************************************************************************** */
static void copy_array(char **src_array, char **dst_array)
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
	*array = NULL;	
}

/* ************************************************************************** */