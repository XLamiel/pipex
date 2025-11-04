/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_satoi_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:17:55 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/10 21:52:43 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/* libft.h

// Definición de códigos de error
#define SATOI_SUCCESS 0
#define SATOI_OVERFLOW 1
#define SATOI_INVALID_CHAR 2
#define SATOI_NO_DIGITS 3
#define SATOI_EMPTY_STRING 4

typedef struct	s_satoi
{
	int	value;
	int	error;
} t_satoi;

*/

size_t	i_skip_spaces(const char *str)
{
	size_t	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

int	i_process_sign(const char *str, size_t *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	i_check_overflow_negative(int value, int digit_val)
{
	if (value < INT_MIN / 10)
		return (1);
	if (value == INT_MIN / 10 && digit_val > -(INT_MIN % 10))
		return (1);
	return (0);
}

int	i_check_overflow_positive(int value, int digit_val)
{
	if (value > INT_MAX / 10)
		return (1);
	if (value == INT_MAX / 10 && digit_val > INT_MAX % 10)
		return (1);
	return (0);
}
