/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 09:43:03 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/11/04 16:45:16 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	left_process(char *argv[], char *envp[], int pipe_fd[])
{
	close(pipe_fd[0]);
	handle_input_redirection(argv[1]);
	redirect_fds(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execute_cmd(argv[2], envp);
}

void	right_process(char *argv[], char *envp[], int pipe_fd[])
{
	int	outfile_fd;

	close(pipe_fd[1]);
	outfile_fd = open_outfile(argv[4]);
	redirect_fds(pipe_fd[0], STDIN_FILENO);
	redirect_fds(outfile_fd, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(outfile_fd);
	execute_cmd(argv[3], envp);
}

int	close_pipe_and_wait(int pipe_fd[], pid_t pid1, pid_t pid2)
{
	int	status;

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
