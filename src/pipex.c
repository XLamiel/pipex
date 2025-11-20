/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 09:43:03 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/11/11 10:52:50 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*

	envp: environment variables.

*/

int	main(int argc, char *argv[], char *envp[])
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		error_message("Error: invalid number of arguments", 1);
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
	return (close_pipe_and_wait(pipe_fd, pid1, pid2));
}
