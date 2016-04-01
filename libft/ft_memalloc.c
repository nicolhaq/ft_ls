/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:08:53 by nhaquet           #+#    #+#             */
/*   Updated: 2013/12/02 16:23:39 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*str;

	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	while (size--)
		str[size] = 0;
	return (str);
}
