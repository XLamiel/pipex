/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:12:33 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/07/17 21:36:50 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_handle_number(va_list args, int base, int uppercase)
{
	long	num;
	char	*str;
	int		len;

	num = va_arg(args, int);
	if (base == 10)
		str = ft_itoa(num);
	else
		str = ft_itoa_base(num, base, uppercase);
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
