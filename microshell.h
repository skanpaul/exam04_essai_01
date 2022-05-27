/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:59:15 by ski               #+#    #+#             */
/*   Updated: 2022/05/27 14:48:39 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H
/* ************************************************************************** */
# define MSG_ERR_ARGC		"error: no command to execute\n"
# define MSG_ERR_CD_FAIL	"error: cd: cannot change directory to path_to_change\n"
# define MSG_ERR_SYSCALL	"error: fatal\n" 
/* ************************************************************************** */
# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "stdbool.h"
/* ************************************************************************** */
bool 	is_fork_error(int fork_code);
bool 	is_fork_child(int fork_code);
bool 	is_fork_parent(int fork_code);
/* ************************************************************************** */
int		print_error(char *msg_error);
/* ************************************************************************** */
void	ft_free(char **str);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
/* ************************************************************************** */
char	*extract_cmd(char *path_and_cmd);
/* ************************************************************************** */
#endif