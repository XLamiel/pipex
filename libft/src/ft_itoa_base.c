/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:08:12 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/07/17 22:36:30 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_numlen_base(unsigned long n, int base)
{
	size_t	len;

	len = 1;
	while (n >= (unsigned long)base)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long n, int base, int uppercase)
{
	char		*str;
	const char	*digits;
	size_t		len;

	if (base < 2 || base > 16)
		return (NULL);
	if (uppercase == 1)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = ft_numlen_base(n, base);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = digits[n % base];
		n /= base;
	}
	return (str);
}
