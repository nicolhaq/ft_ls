/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:19:59 by nhaquet           #+#    #+#             */
/*   Updated: 2018/04/12 14:08:39 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"
#define SIZE 0
#define LINK 1
#define GROUP 2
#define NAME 3
#define BLOCK 4

void	put_buffer(int nb1, int nb2, char *str)
{
	int	ret;

	ret = nb1 - nb2;
	if (ret < 0)
		ret = -ret;
	while (ret > 0)
	{
		ft_strcat(str, " ");
		ret--;
	}
}

void	test_uid(t_list *list, int *uid_ptr)
{
	struct passwd	*psw;

	if ((psw = getpwuid(list->st.st_uid)) != NULL)
	{
		if (ft_strlen(psw->pw_name) > (size_t)*uid_ptr)
			*uid_ptr = ft_strlen(psw->pw_name);
	}
	else
	{
		if (ft_intlen(list->st.st_uid) > *uid_ptr)
			*uid_ptr = ft_intlen(list->st.st_uid);
	}
}

void	test_gid(t_list *list, int *gid_ptr)
{
	struct group	*grp;

	if ((grp = getgrgid(list->st.st_gid)) != NULL)
	{
		if (ft_strlen(grp->gr_name) > (size_t)*gid_ptr)
			*gid_ptr = ft_strlen(grp->gr_name);
	}
	else
	{
		if (ft_intlen(list->st.st_uid) > *gid_ptr)
			*gid_ptr = ft_intlen(list->st.st_uid);
	}
}

void	get_bigest(t_list *list, int size[1][5])
{
	int				*uid_ptr;
	int				*gid_ptr;
	int				maj;

	size[0][SIZE] = 0;
	size[0][LINK] = 0;
	size[0][GROUP] = 0;
	size[0][NAME] = 0;
	size[0][BLOCK] = 0;
	uid_ptr = &size[0][NAME];
	gid_ptr = &size[0][GROUP];
	while (list != NULL)
	{
		maj = minmaj(minor(list->st.st_rdev), major(list->st.st_rdev));
		size[0][BLOCK] = size[0][BLOCK] + list->st.st_blocks;
		if (list->st.st_nlink > (nlink_t)size[0][LINK])
			size[0][LINK] = list->st.st_nlink;
		if ((list->st.st_size > size[0][SIZE]))
			size[0][SIZE] = list->st.st_size;
		else if (maj > size[0][SIZE])
			size[0][SIZE] = maj;
		test_gid(list, gid_ptr);
		test_uid(list, uid_ptr);
		list = list->next;
	}
}

void	print_list(t_list *list, t_parse *parse, char *memstr, int mode)
{
	int		size[5];
	char	str[1024];

	if ((list != NULL) && !(list->st.st_mode & S_IRUSR))
		return ;
	get_bigest(list, &size);
	if ((parse->arg > 0))
		ft_putstr("\n");
	if ((list != NULL) && (parse->l == 1) && (mode == 0))
		display_blocks(size[BLOCK]);
	if (parse->arg > 0)
	{
		display_dir_name(memstr);
	}
	while (list != NULL)
	{
		if (parse->l == 1)
		{
			print_all(list, size, str);
		}
		endline(list, memstr, mode, parse);
		list = list->next;
	}
}
