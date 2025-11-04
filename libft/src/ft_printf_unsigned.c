/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:14:48 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/07/17 21:36:54 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_handle_unsigned(va_list args, int base, int uppercase)
{
	unsigned int	num;
	char			*str;
	int				len;

	num = va_arg(args, unsigned int);
	str = ft_itoa_base(num, base, uppercase);
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
