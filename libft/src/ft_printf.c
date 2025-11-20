/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:16:48 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/07/17 20:41:51 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		tmp;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			tmp = ft_handle_format(&format, args);
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		else
		{
			if (write(1, format++, 1) == -1)
				return (-1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
