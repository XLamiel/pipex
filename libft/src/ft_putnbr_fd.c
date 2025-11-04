/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 05:41:40 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/28 05:44:22 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_handle_min_int(int fd)
{
	ft_putchar_fd('-', fd);
	ft_putchar_fd('2', fd);
	ft_putchar_fd('1', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('7', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('8', fd);
	ft_putchar_fd('3', fd);
	ft_putchar_fd('6', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('8', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_handle_min_int(fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}
