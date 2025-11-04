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

static int open_infile(const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY, 0777);
	if (fd == -1)
	{
		perror(filename);
		return (-1);
	}
	return (fd);
}

static int open_outfile(const char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error_message("Error: cannot open outfile.", 1);
	return (fd);
}

static void redirect_fds(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		error_message("Error: dup2 failed.", 1);
}

static int open_dev_null(void)
{
	int null_fd;

	null_fd = open("/dev/null", O_RDONLY);
	if (null_fd == -1)
	{
		perror("/dev/null");
		return (-1);
	}
	return (null_fd);
}

void left_process(char *argv[], char *envp[], int pipe_fd[])
{
	int infile_fd;
	int null_fd;

	close(pipe_fd[0]);
	infile_fd = open_infile(argv[1]);
	if (infile_fd != -1)
	{
		redirect_fds(infile_fd, STDIN_FILENO);
		close(infile_fd);
	}
	else 
	{
		null_fd = open_dev_null();
		if (null_fd != -1)
		{
			redirect_fds(null_fd, STDIN_FILENO);
			close(null_fd);
		}
	}
	redirect_fds(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execute_cmd(argv[2], envp);
}

void right_process(char *argv[], char *envp[], int pipe_fd[])
{
	int outfile_fd;

	close(pipe_fd[1]);
	outfile_fd = open_outfile(argv[4]);
	redirect_fds(pipe_fd[0], STDIN_FILENO);
	redirect_fds(outfile_fd, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(outfile_fd);
	execute_cmd(argv[3], envp);
}
