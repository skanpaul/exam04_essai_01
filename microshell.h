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
# define MSG_ERR_CD_FAIL	"error: cd: cannot change directory" // path_to_change
# define MSG_ERR_SYSCALL	"error: fatal\n"
# define MSG_ERR_EXECVE		"error: cannot execute " //executable_that_failed
/* ************************************************************************** */
# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "stdbool.h"
# include "string.h"
/* ************************************************************************** */
# include <sys/types.h>
# include <sys/wait.h> 
# include <sys/errno.h>
/* ************************************************************************** */
typedef struct s_param
{
	int		stdin_origin;
	int		stdout_origin;
	int		stderr_origin;
	int		fd_pipe[2];
	int		w_pipe;
	int		r_pipe;
	// ---------------------
	int		argc;
	char	**argv;
	char	**envp;
	// ---------------------
	int		seg_start;
	int		seg_end;
	// ---------------------
	char	*path;
	char	*cmd;
	char	**array;    
	// ---------------------
}   t_param;

/* ************************************************************************** */
void	initialisation(t_param *p, int argc, char **argv, char **envp);
void	clean_program(t_param *p);
/* ************************************************************************** */
void	set_next_seg_start(t_param *p);
void	set_next_seg_end(t_param *p);
void	build_array(t_param *p);
int		run_segment(t_param *p);
bool	does_word_match(char *src, char *hard_str);
/* ************************************************************************** */
bool 	is_fork_error(int fk);
bool 	is_fork_child(int fk);
bool 	is_fork_parent(int fk);
/* ************************************************************************** */
void	create_pipe(t_param *p);
void	set_redirection_out(t_param *p);
void	set_redirection_in(t_param *p);
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
int		print_error(char *msg_error);
void	print_err_execve(t_param *p);
void	print_err_chdir(t_param *p);
int		exit_syscal_err(t_param *p, int err_code);
/* ************************************************************************** */
// void	print_start_child(char **array);
// void	print_end_parent(void);
/* ************************************************************************** */
#endif

