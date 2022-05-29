/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:59:15 by ski               #+#    #+#             */
/*   Updated: 2022/05/29 07:11:39 by sorakann         ###   ########.frchar	   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

/* ************************************************************************** */
# define MSG_ERR_ARGC		"error: no command to execute\n"
# define MSG_ERR_CD_FAIL	"error: cd: cannot change directory to path_to_change\n"
# define MSG_ERR_SYSCALL	"error: fatal\n"
# define MSG_ERR_EXECVE		"error: cannot execute " //executable_that_failed
/* ************************************************************************** */
# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "stdbool.h"
/* ************************************************************************** */
# include <sys/types.h>
# include <sys/wait.h> 
/* ************************************************************************** */
typedef struct s_ep
{
	char *path;
	char **array;
	char **envp;
}	t_ep;

typedef struct s_param
{
	// ---------------------
	int		argc;
	char	**argv;
	char	**envp;
	// ---------------------
	char	*path;
	char	*cmd;
	char	**array;    
	// ---------------------
}   t_param;

/* ************************************************************************** */
void	initialisation(t_param *p, int argc, char **argv, char **envp);
void	run_segment(t_param *p);
void	clean_program(t_param *p);
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
char	*extract_cmd(char *path);
char	**add_string_to_array(char **array, char *new_str);
int		get_size_array(char **array);
void	free_array(char ***array);
void	print_array(char **array);
/* ************************************************************************** */
#endif

