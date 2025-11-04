/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 09:43:03 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/11/04 13:32:23 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (argc != 5)
		error_message("Usage: ./pipex infile cmd1 cmd2 outfile", 1);
	if (pipe(pipe_fd) == -1)
		error_message("Error: pipe creation failed.", 1);
	pid1 = fork();
	if (pid1 == -1)
		error_message("Error: fork failed for cmd1.", 1);
	if (pid1 == 0)
		left_process(argv, envp, pipe_fd);
	pid2 = fork();
	if (pid2 == -1)
		error_message("Error: fork failed for cmd2.", 1);
	if (pid2 == 0)
		right_process(argv, envp, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
