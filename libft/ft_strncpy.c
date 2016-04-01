/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:01:19 by nhaquet           #+#    #+#             */
/*   Updated: 2013/12/01 16:03:59 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *str1, const char *str2, size_t num)
{
	size_t		i;

	i = 0;
	while (i < num && str2[i] != '\0')
	{
		str1[i] = str2[i];
		i++;
	}
	while (i < num)
	{
		str1[i] = '\0';
		i++;
	}
	return (str1);
}
