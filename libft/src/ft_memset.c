/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:43:35 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/27 17:14:54 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
DESCRIPTION
       The memset() function fills the first n bytes of the memory
	   area pointed to by s with the constant byte c.

En resumen:

    Desreferenciar = acceder al valor en la dirección del puntero.

    No se puede desreferenciar un void * directamente,
	porque el compilador no sabe el tipo
	→ no sabe cuántos bytes leer o escribir.

    Solución: hacer un cast a un tipo de puntero concreto.

El codigo optimizado es:
	while (n-- > 0)
		*uc_ptr++ = uc_c;

	return s;

*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*uc_ptr;

	uc_ptr = (unsigned char *)s;
	while (n > 0)
	{
		*uc_ptr = (unsigned char)c;
		n--;
		uc_ptr++;
	}
	return (s);
}
