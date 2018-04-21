/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:59:43 by nhaquet           #+#    #+#             */
/*   Updated: 2018/04/12 14:08:01 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void				display_type(t_list *list, char *str)
{
	if (S_ISLNK(list->st.st_mode))
		str = ft_strcat(str, "l");
	else if (S_ISFIFO(list->st.st_mode))
		str = ft_strcat(str, "p");
	else if (S_ISBLK(list->st.st_mode))
		str = ft_strcat(str, "b");
	else if (S_ISCHR(list->st.st_mode))
		str = ft_strcat(str, "c");
	else if (S_ISDIR(list->st.st_mode))
		str = ft_strcat(str, "d");
	else if (S_ISSOCK(list->st.st_mode))
		str = ft_strcat(str, "s");
	else
		str = ft_strcat(str, "-");
}

void				display_fr(t_list *list, char *str)
{
	str = ft_strcat(str, ((list->st.st_mode & S_IRUSR) ? "r" : "-"));
	str = ft_strcat(str, ((list->st.st_mode & S_IWUSR) ? "w" : "-"));
	str = ft_strcat(str, ((list->st.st_mode & S_IXUSR) ? "x" : "-"));
	str = ft_strcat(str, ((list->st.st_mode & S_IRGRP) ? "r" : "-"));
	str = ft_strcat(str, ((list->st.st_mode & S_IWGRP) ? "w" : "-"));
	str = ft_strcat(str, ((list->st.st_mode & S_IXGRP) ? "x" : "-"));
	str = ft_strcat(str, ((list->st.st_mode & S_IROTH) ? "r" : "-"));
	str = ft_strcat(str, ((list->st.st_mode & S_IWOTH) ? "w" : "-"));
	str = ft_strcat(str, ((list->st.st_mode & S_IXOTH) ? "x" : "-"));
	str = ft_strcat(str, "  ");
}

void				display_nm(t_list *list, int name_len, char *str)
{
	struct passwd	*psw;
	char			*mem;

	if ((psw = getpwuid(list->st.st_uid)) == NULL)
	{
		mem = ft_itoa(list->st.st_uid);
		str = ft_strcat(str, mem);
		free(mem);
		str = ft_strcat(str, "  ");
		put_buffer(name_len, ft_intlen(list->st.st_uid), str);
	}
	else
	{
		str = ft_strcat(str, psw->pw_name);
		str = ft_strcat(str, "  ");
		put_buffer(name_len, ft_strlen(psw->pw_name), str);
	}
}

void				display_gr(t_list *list, int grp_len, char *str)
{
	struct group	*grp;
	char			*mem;

	if ((grp = getgrgid(list->st.st_gid)) == NULL)
	{
		mem = ft_itoa(list->st.st_gid);
		str = ft_strcat(str, mem);
		free(mem);
		str = ft_strcat(str, "  ");
		put_buffer(grp_len, ft_intlen(list->st.st_gid), str);
	}
	else
	{
		str = ft_strcat(str, grp->gr_name);
		str = ft_strcat(str, "  ");
		put_buffer(grp_len, ft_strlen(grp->gr_name), str);
	}
}

void				display_link(t_list *list, char *memstr, int mode)
{
	char			buff[1024];
	int				len;
	char			*str;

	str = memstr;
	if (S_ISLNK(list->st.st_mode))
	{
		if (mode == 0)
			str = join_path(memstr, list->dir_mem.d_name);
		len = readlink(str, buff, sizeof(buff) - 1);
		if (len == -1)
			return ;
		buff[len] = '\0';
		ft_putstr(" -> ");
		ft_putstr(buff);
		if (mode == 0)
			free(str);
	}
}
