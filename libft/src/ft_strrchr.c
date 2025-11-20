/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:19:14 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/16 22:00:47 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* while (*s != '\0') */
/* while (*s) */

char	*ft_strrchr(const char *s, int c)
{
	char	*last_prt;

	last_prt = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_prt = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		last_prt = (char *)s;
	return (last_prt);
}
