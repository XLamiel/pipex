/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:20:52 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/16 20:43:27 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* while (*s != '\0' && *s != (char)c) */
/* while (*s && *s != (char)c) */

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
