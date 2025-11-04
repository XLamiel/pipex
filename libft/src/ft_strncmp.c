/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:46:13 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/27 17:42:42 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
		if (s1[i] == '\0')
		{
			break ;
		}
		i++;
	}
	return (0);
}

/*
#include<stdio.h>

int	main(void)
{
	printf("AA contra AA es: %d\n", ft_strncmp("AA", "AA", 2));
	printf("ABC contra AB es: %d\n", ft_strncmp("ABC", "AB", 3));
	printf("ABA contra ABZ es: %d\n", ft_strncmp("ABA", "ABZ", 3));
}
*/
