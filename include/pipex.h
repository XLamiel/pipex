/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tu_nombre <tu_mail@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 00:00:00 by tu_nombre         #+#    #+#             */
/*   Updated: 2025/11/04 17:22:19 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>      // open
# include <stdio.h>      // perror
# include <stdlib.h>     // malloc, free, exit
# include <string.h>     // strerror
# include <sys/types.h>  // pid_t
# include <sys/wait.h>   // waitpid
# include <unistd.h>     // pipe, dup2, access, execve, close, write

# include "libft.h"   // ft_split, ft_strjoin, ft_strdup, etc.

/* main.c */
int		main(int argc, char *argv[], char *envp[]);

/* process.c */
void	left_process(char *argv[], char *envp[], int pipe_fd[]);
void	right_process(char *argv[], char *envp[], int pipe_fd[]);

/* exec_utils.c */
void	execute_cmd(char *argv, char *envp[]);
void	ft_free_words(char **arr);

/* path_utils.c */
char	*get_path(char *cmd, char *envp[]);

/* split_quotes */
char	**ft_split_quotes(char const *s);
char	*trim_outer_quotes(char *str);

/* error.c */
void	error_message(char *message, int exit_code);

#endif
