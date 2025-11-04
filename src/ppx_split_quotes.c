/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_split_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:34:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/11/04 15:48:11 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_tokens_quotes(char const *s)
{
	int	count;
	int	in_squote;
	int	in_dquote;
	int	in_token;

	count = 0;
	in_squote = 0;
	in_dquote = 0;
	in_token = 0;
	while (*s)
	{
		if (*s == '\'' && !in_dquote)
			in_squote = !in_squote;
		else if (*s == '"' && !in_squote)
			in_dquote = !in_dquote;
		if (!in_squote && !in_dquote && *s == ' ')
			in_token = 0;
		else if (!in_token)
		{
			count++;
			in_token = 1;
		}
		s++;
	}
	return (count);
}

static char	*extract_token(char const *s, int start, int end)
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

char	**ft_split_quotes(char const *s)
{
	char	**result;
	int		i;
	int		start;
	int		in_squote;
	int		in_dquote;
	int		count;

	if (!s)
		return (NULL);
	count = count_tokens_quotes(s);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	in_squote = 0;
	in_dquote = 0;
	start = -1;
	count = 0;
	while (s[i])
	{
		if (start == -1 && s[i] != ' ')
			start = i;
		if (s[i] == '\'' && !in_dquote)
			in_squote = !in_squote;
		else if (s[i] == '"' && !in_squote)
			in_dquote = !in_dquote;
		if (start != -1 && !in_squote && !in_dquote && (s[i] == ' ' || s[i + 1] == '\0'))
		{
			result[count] = extract_token(s, start, i);
			if (!result[count])
			{
				ft_free_words(result);
				return (NULL);
			}
			count++;
			start = -1;
		}
		i++;
	}
	result[count] = NULL;
	return (result);
}

char	*trim_outer_quotes(char *str)
{
	size_t	len;
	char	*result;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len >= 2 && ((str[0] == '\'' && str[len - 1] == '\'') || 
		(str[0] == '"' && str[len - 1] == '"')))
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
