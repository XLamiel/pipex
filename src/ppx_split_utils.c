/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_split_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:34:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/11/04 15:48:11 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_split_quotes(char const *s)
{
	char		**result;
	t_splitter	state;

	state = (t_splitter){0, 0, 0, 0, -1, 0};
	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_tokens_quotes(s) + 1));
	if (!result)
		return (NULL);
	while (s[state.i])
	{
		if (state.start == -1 && s[state.i] != ' ')
			state.start = state.i;
		handle_quotes_update_state(s[state.i], &state);
		if (is_space_or_end(s, &state))
		{
			if (!store_token_and_update_state(s, &state, result))
				return (NULL);
		}
		state.i++;
	}
	result[state.count] = NULL;
	return (result);
}

char	*trim_outer_quotes(char *str)
{
	size_t	len;
	char	*result;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len >= 2 && ((str[0] == '\'' && str[len - 1] == '\'')
			|| (str[0] == '"' && str[len - 1] == '"')))
	{
		result = malloc(len - 1);
		if (!result)
			return (NULL);
		ft_strlcpy(result, str + 1, len - 1);
		free(str);
		return (result);
	}
	return (str);
}
