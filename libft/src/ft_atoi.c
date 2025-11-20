/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:49:33 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/27 18:24:32 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isspace(char c)
{
	if (c == ' ')
		return (c == ' ');
	if (c == '\t')
		return (c == '\t');
	if (c == '\n')
		return (c == '\n');
	if (c == '\v')
		return (c == '\v');
	if (c == '\f')
		return (c == '\f');
	if (c == '\r')
		return (c == '\r');
	return (0);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			result;
	size_t		i;

	sign = 1;
	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
