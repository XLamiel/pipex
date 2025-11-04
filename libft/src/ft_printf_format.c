/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:15:39 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/07/17 21:36:58 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_handle_format(const char **format, va_list args)
{
	int	len;

	len = 0;
	(*format)++;
	if (**format == 'c')
		len = ft_handle_char(args);
	else if (**format == 's')
		len = ft_handle_string(args);
	else if (**format == 'p')
		len = ft_handle_pointer(args);
	else if (**format == 'd' || **format == 'i')
		len = ft_handle_number(args, 10, 0);
	else if (**format == 'u')
		len = ft_handle_unsigned(args, 10, 0);
	else if (**format == 'x')
		len = ft_handle_unsigned(args, 16, 0);
	else if (**format == 'X')
		len = ft_handle_unsigned(args, 16, 1);
	else if (**format == '%')
		len = write(1, "%", 1);
	else
		len = -1;
	(*format)++;
	return (len);
}
