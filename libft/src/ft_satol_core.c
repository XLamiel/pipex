/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_satol_core.c                                    :+:      :+:    :+:   */
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

int	l_process_next_digit(long *value, int digit_val, long sign)
{
	if (sign == 1)
	{
		if (l_check_overflow_positive(*value, digit_val))
			return (SATOL_OVERFLOW);
		*value = *value * 10 + digit_val;
	}
	else
	{
		if (l_check_overflow_negative(*value, digit_val))
			return (SATOL_OVERFLOW);
		*value = *value * 10 - digit_val;
	}
	return (SATOL_SUCCESS);
}

int	l_handle_overflow(t_satol *result, long sign, size_t *i, const char *str)
{
	result->error = SATOL_OVERFLOW;
	if (sign == 1)
		result->value = LONG_MAX;
	else
		result->value = LONG_MIN;
	while (ft_isdigit(str[*i]))
		(*i)++;
	return (SATOL_OVERFLOW);
}

int	l_process_digit_loop(const char *str, size_t *i, t_satol *result, long sign)
{
	int	has_digits;
	int	error;

	has_digits = 0;
	while (ft_isdigit(str[*i]))
	{
		has_digits = 1;
		error = l_process_next_digit(&result->value, str[*i] - '0', sign);
		if (error != SATOL_SUCCESS)
			return (l_handle_overflow(result, sign, i, str));
		(*i)++;
	}
	if (has_digits)
		return (SATOL_SUCCESS);
	else
		return (SATOL_NO_DIGITS);
}

int	l_convert_digits(const char *str, size_t *i, t_satol *result, long sign)
{
	int	error_code;

	error_code = l_process_digit_loop(str, i, result, sign);
	if (error_code != SATOL_SUCCESS)
	{
		if (error_code == SATOL_NO_DIGITS)
			result->error = SATOL_NO_DIGITS;
		return (error_code);
	}
	return (SATOL_SUCCESS);
}

t_satol	l_parse_digits(const char *str, size_t *i, long sign)
{
	t_satol	result;
	int		error_code;

	result.value = 0;
	result.error = SATOL_SUCCESS;
	error_code = l_convert_digits(str, i, &result, sign);
	if (error_code != SATOL_SUCCESS)
	{
		result.error = error_code;
	}
	return (result);
}
