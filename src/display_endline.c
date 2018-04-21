/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_endline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:57:33 by nhaquet           #+#    #+#             */
/*   Updated: 2018/04/12 14:04:42 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	endline(t_list *list, char *memstr, int mode, t_parse *parse)
{
	if (mode == 0)
		ft_putstr(list->dir_mem.d_name);
	else
		ft_putstr(memstr);
	if (parse->l == 1)
		display_link(list, memstr, mode);
	ft_putstr("\n");
}

void	display_minmaj(t_list *list, int size, char *str)
{
	int		maj;
	char	*mem;
	char	*mem2;

	maj = 0;
	mem = ft_itoa(major(list->st.st_rdev));
	maj = ft_intlen(minor(list->st.st_rdev)) +
	ft_intlen(major(list->st.st_rdev)) + 2;
	ft_strcat(str, mem);
	free(mem);
	ft_strcat(str, ",");
	put_buffer(ft_intlen(size), maj, str);
	mem2 = ft_itoa(minor(list->st.st_rdev));
	ft_strcat(str, mem2);
	free(mem2);
	ft_strcat(str, " ");
}
