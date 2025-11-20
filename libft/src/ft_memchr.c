/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:37:34 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/20 17:52:27 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uc_ptr;

	uc_ptr = (const unsigned char *)s;
	while (n > 0)
	{
		if (*uc_ptr == (unsigned char)c)
			return ((void *)uc_ptr);
		uc_ptr++;
		n--;
	}
	return (NULL);
}
