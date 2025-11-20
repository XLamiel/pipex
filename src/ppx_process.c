/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 09:43:03 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/11/06 18:14:31 by xlamiel-         ###   ########.fr       */
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

/*
	<sys/wait.h>
	#define WIFEXITED(status)   (((status) & 0x7F) == 0)
	#define WEXITSTATUS(status) (((status) >> 8) & 0xFF)

	(status & 0x7F) == 0
		check that the 7 low bits are 0 → the process
        was not terminated by a signal, therefore
		it terminated normally
	(status >> 8) & 0xFF
		take bits 8–15 → the process exit code
*/

int	close_pipe_and_wait(int pipe_fd[], pid_t pid1, pid_t pid2)
{
	int	status;

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if ((status & 0x7F) == 0)
		return ((status >> 8) & 0xFF);
	return (1);
}
