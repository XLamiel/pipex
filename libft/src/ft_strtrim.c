/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 23:19:06 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/28 00:05:03 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_is_in_set(char c, char const *set)
{
	return (ft_strchr(set, c) != NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_is_in_set(s1[end - 1], set))
		end--;
	trimmed = (char *)malloc(sizeof(char) * (end - start + 1));
	if (trimmed == NULL)
		return (NULL);
	ft_memcpy(trimmed, s1 + start, end - start);
	trimmed[end - start] = '\0';
	return (trimmed);
}

/*
Importante!!!

Al igual que en ft_strjoin...

ft_memcpy(trimmed, s1 + start, end - start);

trimmed
	Nueva arr de char generado por malloc
s1 + start
	Aritmetica de punteros:
		s1 es un puntero de un arr de char 
			y apunta a (invento) 00001
		start es un size_t a modo de indice
		que indica que el valor de ese arr no 
		coincide con el valor a trimear (ejem)
		"  Hola ", es decir 2
		=
		Entonces 00001 + 2 = 00003
*/
