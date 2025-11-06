/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 09:43:03 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/11/05 13:32:23 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> // To pipe, dup2, access
# include <fcntl.h> // (File Control) To open, write...
# include <stdlib.h>
# include <sys/wait.h> // To pid_t, waitpid, WIFEXITED, WEXITSTATUS
# include <stdio.h>    // To perror()

/*
 * Estructura utilizada para el manejo de comillas en ft_split_quotes.
 * Rastrea si estamos dentro de comillas simples o dobles.
 */
typedef struct s_splitter
{
	int	in_squote;
	int	in_dquote;
	int	in_token;
	int	count;
	int	start;
	int	i;
}	t_splitter;

/* --- funciones de Libft --- */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/* --- Funciones de Memoria (ppx_memory.c) --- */
void	ft_free_words(char **arr);
char	*ft_split_quotes_mem_err(char **arr, int exit_code);

/* --- Funciones de Error (ppx_error.c) --- */
void	error_message(char *message, int exit_code);

/* --- Funciones de I/O (ppx_io.c) --- */
void	redirect_fds(int oldfd, int newfd);
int		open_infile(const char *filename);
int		open_outfile(const char *filename);
void	handle_input_redirection(const char *filename);

/* --- Funciones de Split Core (ppx_split_utils.c) --- */
char	*trim_outer_quotes(char *str);
char	**ft_split_quotes(char const *s);

/* --- Funciones de Split Auxiliares (ppx_split_helpers.c) --- */
int		is_space_or_end(char const *s, t_splitter *state);
int		count_tokens_quotes(char const *s);
char	*extract_token(char const *s, int start, int end);
int		store_token_and_update_state(char const *s, t_splitter *state,
			char **result);
void	handle_quotes_update_state(char c, t_splitter *state);

/* --- Funciones de Ejecución (ppx_exec.c) */
void	execute_cmd(char *argv, char *envp[]);

/* --- Funciones de Path (ppx_path.c) --- */
char	*get_path(char *cmd, char *envp[]);

/* --- Funciones de Proceso (ppx_process.c) --- */
void	left_process(char *argv[], char *envp[], int pipe_fd[]);
void	right_process(char *argv[], char *envp[], int pipe_fd[]);
int		close_pipe_and_wait(int pipe_fd[], pid_t pid1, pid_t pid2);

#endif
