/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_satoi_core.c                                    :+:      :+:    :+:   */
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

int	i_process_next_digit(int *value, int digit_val, int sign)
{
	if (sign == 1)
	{
		if (i_check_overflow_positive(*value, digit_val))
			return (SATOI_OVERFLOW);
		*value = *value * 10 + digit_val;
	}
	else
	{
		if (i_check_overflow_negative(*value, digit_val))
			return (SATOI_OVERFLOW);
		*value = *value * 10 - digit_val;
	}
	return (SATOI_SUCCESS);
}

int	i_handle_overflow(t_satoi *result, int sign, size_t *i, const char *str)
{
	result->error = SATOI_OVERFLOW;
	if (sign == 1)
		result->value = INT_MAX;
	else
		result->value = INT_MIN;
	while (ft_isdigit(str[*i]))
		(*i)++;
	return (SATOI_OVERFLOW);
}

int	i_process_digit_loop(const char *str, size_t *i, t_satoi *result, int sign)
{
	int	has_digits;
	int	error;

	has_digits = 0;
	while (ft_isdigit(str[*i]))
	{
		has_digits = 1;
		error = i_process_next_digit(&result->value, str[*i] - '0', sign);
		if (error != SATOI_SUCCESS)
			return (i_handle_overflow(result, sign, i, str));
		(*i)++;
	}
	if (has_digits)
		return (SATOI_SUCCESS);
	else
		return (SATOI_NO_DIGITS);
}

int	i_convert_digits(const char *str, size_t *i, t_satoi *result, int sign)
{
	int	error_code;

	error_code = i_process_digit_loop(str, i, result, sign);
	if (error_code != SATOI_SUCCESS)
	{
		if (error_code == SATOI_NO_DIGITS)
			result->error = SATOI_NO_DIGITS;
		return (error_code);
	}
	return (SATOI_SUCCESS);
}

t_satoi	i_parse_digits(const char *str, size_t *i, int sign)
{
	t_satoi	result;
	int		error_code;

	result.value = 0;
	result.error = SATOI_SUCCESS;
	error_code = i_convert_digits(str, i, &result, sign);
	if (error_code != SATOI_SUCCESS)
	{
		result.error = error_code;
	}
	return (result);
}
