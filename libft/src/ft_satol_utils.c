/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_satol_utils.c                                   :+:      :+:    :+:   */
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
#define SATOL_SUCCESS 0
#define SATOL_OVERFLOW 1
#define SATOL_INVALID_CHAR 2
#define SATOL_NO_DIGITS 3
#define SATOL_EMPTY_STRING 4

// error 0, success 1
typedef struct	s_satol
{
	long	value;
	int		error;
} t_satol;

*/

size_t	l_skip_spaces(const char *str)
{
	size_t	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

long	l_process_sign(const char *str, size_t *i)
{
	long	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	l_check_overflow_negative(long value, int digit_val)
{
	if (value < LONG_MIN / 10)
		return (1);
	if (value == LONG_MIN / 10 && digit_val > -(LONG_MIN % 10))
		return (1);
	return (0);
}

int	l_check_overflow_positive(long value, int digit_val)
{
	if (value > LONG_MAX / 10)
		return (1);
	if (value == LONG_MAX / 10 && digit_val > LONG_MAX % 10)
		return (1);
	return (0);
}
