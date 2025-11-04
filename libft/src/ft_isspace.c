/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:51:57 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/10 21:53:15 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
