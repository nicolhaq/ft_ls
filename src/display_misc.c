/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_misc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:21:18 by nhaquet           #+#    #+#             */
/*   Updated: 2018/04/12 14:05:51 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"
#define SIZE 0
#define LINK 1
#define GROUP 2
#define NAME 3
#define BLOCK 4

void	display_link_nb(t_list *list, int link, char *str)
{
	char	*mem;

	mem = ft_itoa(list->st.st_nlink);
	put_buffer(ft_intlen(link), ft_intlen(list->st.st_nlink), str);
	str = ft_strcat(str, mem);
	free(mem);
	str = ft_strcat(str, " ");
}

void	display_size(t_list *list, int size, char *str)
{
	char	*mem;

	mem = ft_itoa(list->st.st_size);
	put_buffer(ft_intlen(size), ft_intlen(list->st.st_size), str);
	str = ft_strcat(str, mem);
	free(mem);
	str = ft_strcat(str, " ");
}

void	display_blocks(int blocks)
{
	ft_putstr("total ");
	ft_putnbr(blocks);
	ft_putstr("\n");
}

void	print_all(t_list *list, int *size, char *str)
{
	ft_bzero(str, 1024);
	display_type(list, str);
	display_fr(list, str);
	display_link_nb(list, size[LINK], str);
	display_nm(list, size[NAME], str);
	display_gr(list, size[GROUP], str);
	if (S_ISCHR(list->st.st_mode))
		display_minmaj(list, size[SIZE], str);
	else
		display_size(list, size[SIZE], str);
	display_time(list, str);
	ft_putstr(str);
}

void	display_dir_name(char *memstr)
{
	ft_putstr(memstr);
	ft_putstr(":\n");
}
