/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 09:43:03 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/11/04 15:56:53 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**parse_command(char *argv)
{
	char	**cmd;
	char	*trimmed;
	int		i;

	if (!argv)
		error_message("Error: no command provided", 1);
	cmd = ft_split_quotes(argv);
	if (!cmd || !cmd[0])
	{
		ft_free_words(cmd);
		error_message("Error: invalid command", 127);
	}
	i = 0;
	while (cmd[i])
	{
		trimmed = trim_outer_quotes(cmd[i]);
		if (!trimmed)
		{
			ft_free_words(cmd);
			error_message("Error: memory allocation failed", 1);
		}
		cmd[i] = trimmed;
		i++;
	}
	return (cmd);
}

static void	execve_with_error(char *path, char **cmd, char *envp[])
{
	if (execve(path, cmd, envp) == -1)
	{
		perror("Error: execve()");
		free(path);
		ft_free_words(cmd);
		exit(127);
	}
}

static void	handle_cmd_not_found(char *cmd_name, char **cmd)
{
	write(2, cmd_name, ft_strlen(cmd_name));
	write(2, ": command not found\n", 20);
	free(cmd_name);
	ft_free_words(cmd);
	exit(127);
}

static void	prep_and_exec(char **cmd, char *envp[])
{
	char	*path;
	char	*cmd_name;

	cmd_name = ft_strdup(cmd[0]);
	if (!cmd_name)
	{
		ft_free_words(cmd);
		error_message("Error: memory allocation failed", 1);
	}
	path = get_path(cmd[0], envp);
	if (!path)
	{
		handle_cmd_not_found(cmd_name, cmd);
	}
	free(cmd_name);
	execve_with_error(path, cmd, envp);
}

void	execute_cmd(char *argv, char *envp[])
{
	char	**cmd;

	if (!argv || !envp)
		error_message("Error: no arguments/envp", 1);
	cmd = parse_command(argv);
	prep_and_exec(cmd, envp);
}
