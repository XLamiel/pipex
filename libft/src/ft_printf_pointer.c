/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:11:33 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/07/17 22:53:39 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	write_pointer_value(unsigned long addr)
{
	char	*hex_str;
	int		len;

	hex_str = ft_itoa_base(addr, 16, 0);
	if (!hex_str)
		return (-1);
	len = write(1, hex_str, ft_strlen(hex_str));
	free(hex_str);
	return (len);
}

int	ft_handle_pointer(va_list args)
{
	void	*ptr;
	int		total_len;
	int		res;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	total_len = write(1, "0x", 2);
	if (total_len == -1)
		return (-1);
	res = write_pointer_value((unsigned long)ptr);
	if (res == -1)
		return (-1);
	return (total_len + res);
}
