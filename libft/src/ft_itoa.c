/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 03:43:59 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/28 03:49:59 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	ft_fill_str(char *str, int n, int digits)
{
	int	is_negative;

	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	str[digits] = '\0';
	while (digits > is_negative)
	{
		digits--;
		str[digits] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digits = ft_count_digits(n);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		return (NULL);
	ft_fill_str(str, n, digits);
	return (str);
}
