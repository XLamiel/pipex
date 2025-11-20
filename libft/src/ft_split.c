/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 01:00:17 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/28 18:08:51 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_free_words(char **arr, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*get_next_word(char const **s, char c)
{
	size_t		len;
	char		*word;

	while (**s == c)
		(*s)++;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, *s, len + 1);
	*s += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		word_count;
	size_t		i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		result[i] = get_next_word(&s, c);
		if (!result[i])
		{
			ft_free_words(result, i);
			return (NULL);
		}
		i++;
	}
	result[word_count] = NULL;
	return (result);
}

/*

1. ft_count_words
	1.1. Cuantas palabras hay en "s", separadas por "c"?
2. ft_word_len
	2.1. Calcula la longitud de una palabra desde "s"
	hasta el próximo delimitador "c" o fin "\0"
3. ft_get_word
	3.1. Extrae una palabra y reserva memoria para copiarla
4. ft_init_result_array *Candidat a integrar
	4.1. Reserva un array de punteros "char **" para guardar las palabras
5. ft_free_result
	5.1. Libera toda la memoria si ocurre un error durante el procesamiento
6. ft_process_words
	6.1. Extrae cada palabra usando las funciones anteriores
7. ft_split
	7.1. Funcion principal

Despues de separarlo todo, ahora hay muchas funciones,
ME CAGO EN TODOS LOS MUERTOS!

size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_init_result_array(size_t word_count)
{
	char	**result;

	result = (char **)calloc(word_count + 1, sizeof(char *));
	return (result);
}

*/
