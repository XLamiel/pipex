/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_path_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 09:43:03 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/11/04 14:00:28 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char **get_env_paths(char *envp[])
{
	int i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

static char *join_path_cmd(char *directory, char *cmd)
{
	char *temp;
	char *full_path;

	temp = ft_strjoin(directory, "/");
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, cmd);
	free(temp);
	return (full_path);
}

char *get_path(char *cmd, char *envp[])
{
	char **paths;
	char *full_path;
	int i;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	paths = get_env_paths(envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = join_path_cmd(paths[i], cmd);
		if (!full_path)
		{
			ft_free_words(paths);
			return (NULL);
		}
		if (access(full_path, F_OK | X_OK) == 0)
		{
			ft_free_words(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	ft_free_words(paths);
	return (NULL);
}
