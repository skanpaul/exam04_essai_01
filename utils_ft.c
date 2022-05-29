/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 09:41:12 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 09:41:43 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
int ft_strlen(char *str)
{
	int i;

	if(!str)
		return(0);
	i = 0;
	while (str[i])
		i++;
	return (i);	
}

// /* ************************************************************************** */
void ft_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;	
}

// /* ************************************************************************** */
char *ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*new_string;
	
	if(!str)
		return NULL;
	len = ft_strlen(str);

	new_string = (char *)malloc(sizeof(char) * (len + 1));

	if (!new_string)
		return NULL;
		
	i = 0;
	while (str[i])
	{
		new_string[i] = str[i];
		i++;
	}
	new_string[i] = '\0';	
	return new_string;
}

/* ************************************************************************** */