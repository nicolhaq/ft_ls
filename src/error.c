/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:45:15 by nhaquet           #+#    #+#             */
/*   Updated: 2018/04/12 14:06:55 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	print_error(char *file)
{
	ft_putstr("ls: ");
	if (errno == 2)
		ft_putstr(file);
	else if (errno != 0 || errno != 20)
		perror(file);
	if (errno == 2)
		ft_putstr(": No such file or directory");
	if (errno == 2)
		ft_putstr("\n");
}

void	flush_dir(t_list *list, DIR *dir)
{
	free_list(list);
	closedir(dir);
}

int		minmaj(int min, int maj)
{
	int	ret;
	int	i;

	ret = 1;
	i = ft_intlen(minor(min)) + ft_intlen(major(maj)) + 3;
	while (i > 0)
	{
		ret = ret * 10;
		i--;
	}
	return (ret);
}
