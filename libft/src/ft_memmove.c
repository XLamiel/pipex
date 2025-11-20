/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:31:49 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/23 19:47:23 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_reverse_cpy(const unsigned char *uc_s, unsigned char *uc_d, size_t n)
{
	while (n > 0)
	{
		n--;
		uc_d[n] = uc_s[n];
	}
}

void	ft_direct_cpy(const unsigned char *uc_s, unsigned char *uc_d, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		uc_d[i] = uc_s[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*uc_s;
	unsigned char		*uc_d;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	uc_s = (const unsigned char *)src;
	uc_d = (unsigned char *)dest;
	if (uc_d > uc_s && uc_d < uc_s + n)
		ft_reverse_cpy(uc_s, uc_d, n);
	else
		ft_direct_cpy(uc_s, uc_d, n);
	return (dest);
}
