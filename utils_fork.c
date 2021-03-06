/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:11:32 by ski               #+#    #+#             */
/*   Updated: 2022/05/30 06:10:16 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/* ************************************************************************** */
bool is_fork_error(int fk)
{
	if (fk == -1)
		return true;
	return false;
}

/* ************************************************************************** */
bool is_fork_child(int fk)
{
	if (fk == 0)
		return true;
	return false;
}

/* ************************************************************************** */
bool is_fork_parent(int fk)
{
	if (fk > 0)
		return true;
	return false;
}

/* ************************************************************************** */
