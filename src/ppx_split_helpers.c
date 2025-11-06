/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_split_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:34:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/11/04 15:48:11 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_space_or_end(char const *s, t_splitter *state)
{
	return (state->start != -1 && !state->in_squote && !state->in_dquote
		&& (s[state->i] == ' ' || s[state->i + 1] == '\0'));
}

int	count_tokens_quotes(char const *s)
{
	t_splitter	state;

	state.count = 0;
	state.in_squote = 0;
	state.in_dquote = 0;
	state.in_token = 0;
	while (*s)
	{
		if (*s == '\'' && !state.in_dquote)
			state.in_squote = !state.in_squote;
		else if (*s == '"' && !state.in_squote)
			state.in_dquote = !state.in_dquote;
		if (!state.in_squote && !state.in_dquote && *s == ' ')
			state.in_token = 0;
		else if (!state.in_token)
		{
			state.count++;
			state.in_token = 1;
		}
		s++;
	}
	return (state.count);
}

char	*extract_token(char const *s, int start, int end)
{
	char	*token;
	int		len;

	if (s[end] != ' ' && s[end] != '\0')
		end++;
	len = end - start;
	token = malloc(len + 1);
	if (!token)
		return (NULL);
	ft_strlcpy(token, s + start, len + 1);
	return (token);
}

int	store_token_and_update_state(char const *s, t_splitter *state,
				char **result)
{
	result[state->count] = extract_token(s, state->start, state->i);
	if (!result[state->count])
	{
		ft_split_quotes_mem_err(result, 0);
		return (0);
	}
	state->count++;
	state->start = -1;
	return (1);
}

void	handle_quotes_update_state(char c, t_splitter *state)
{
	if (c == '\'' && !state->in_dquote)
		state->in_squote = !state->in_squote;
	else if (c == '"' && !state->in_squote)
		state->in_dquote = !state->in_dquote;
}
