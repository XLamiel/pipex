/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:07:29 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/27 17:44:12 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*uc_dest;
	unsigned char	*uc_src;

	if (!dest && !src)
		return (dest);
	uc_dest = (unsigned char *)dest;
	uc_src = (unsigned char *)src;
	while (n--)
		*uc_dest++ = *uc_src++;
	return (dest);
}
