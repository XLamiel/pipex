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

typedef struct s_splitter
{
	int	in_squote;
	int	in_dquote;
	int	in_token;
	int	count;
	int	start;
	int	i;
}	t_splitter;

/* --- Libft --- */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/* --- (ppx_memory.c) --- */
void	ft_free_words(char **arr);
char	*ft_split_quotes_mem_err(char **arr, int exit_code);

/* --- (ppx_error.c) --- */
void	error_message(char *message, int exit_code);

/* --- (ppx_io.c) --- */
void	redirect_fds(int oldfd, int newfd);
int		open_infile(const char *filename);
int		open_outfile(const char *filename);
void	handle_input_redirection(const char *filename);

/* --- (ppx_split_utils.c) --- */
char	*trim_outer_quotes(char *str);
char	**ft_split_quotes(char const *s);

/* --- (ppx_split_helpers.c) --- */
int		is_space_or_end(char const *s, t_splitter *state);
int		count_tokens_quotes(char const *s);
char	*extract_token(char const *s, int start, int end);
int		store_token_and_update_state(char const *s, t_splitter *state,
			char **result);
void	handle_quotes_update_state(char c, t_splitter *state);

/* --- (ppx_exec.c) */
void	execute_cmd(char *argv, char *envp[]);

/* --- (ppx_path.c) --- */
char	*get_path(char *cmd, char *envp[]);

/* --- (ppx_process.c) --- */
void	left_process(char *argv[], char *envp[], int pipe_fd[]);
void	right_process(char *argv[], char *envp[], int pipe_fd[]);
int		close_pipe_and_wait(int pipe_fd[], pid_t pid1, pid_t pid2);

#endif
