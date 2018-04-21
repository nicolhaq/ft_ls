/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 18:31:30 by nhaquet           #+#    #+#             */
/*   Updated: 2014/01/10 18:46:25 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *mem, size_t new_size)
{
	void	*new_mem;
	size_t	old_size;

	if (!mem)
		return (NULL);
	old_size = ft_strlen((char *)mem);
	if (old_size == 0)
		return (mem);
	new_mem = ft_memalloc(new_size);
	if (!new_mem)
		return (NULL);
	ft_memcpy(new_mem, mem, old_size);
	free(mem);
	return (new_mem);
}
