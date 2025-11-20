/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:43:03 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/11/05 13:32:23 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0777);
	if (fd == -1)
	{
		perror(filename);
		return (-1);
	}
	return (fd);
}

int	open_outfile(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error_message("Error: cannot open outfile.", 1);
	return (fd);
}

void	redirect_fds(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		error_message("Error: dup2 failed.", 1);
}

static int	open_dev_null(void)
{
	int	null_fd;

	null_fd = open("/dev/null", O_RDONLY);
	if (null_fd == -1)
	{
		perror("/dev/null");
		return (-1);
	}
	return (null_fd);
}

void	handle_input_redirection(const char *filename)
{
	int	infile_fd;
	int	null_fd;

	infile_fd = open_infile(filename);
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
}
