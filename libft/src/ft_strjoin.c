/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:45:00 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/27 23:02:26 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s1, s1_len);
	ft_memcpy(new_str + s1_len, s2, s2_len);
	new_str[s1_len + s2_len] = '\0';
	return (new_str);
}

/*
Importante!!!

ft_memcpy(new_str + s1_len, s2, s2_len);

new_str + s1_len
	Aritmetica de punteros:
		new_str es un puntero de un arr de char 
			y apunta a (invento) 00001
		s1_len es un size_t de (ejem) "Hola ", es decir 5
		=
		Entonces 00001 + 5 = 00006
		00006 es el puntero justo donde debe concatenarse
			s2.
*/
