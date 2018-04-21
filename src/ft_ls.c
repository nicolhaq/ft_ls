/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 23:49:32 by nhaquet           #+#    #+#             */
/*   Updated: 2018/04/12 13:40:08 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../include/ft_ls.h"

char				*join_path(char *path, char *dir)
{
	char			*ret;
	char			*meme;
	int				i;

	i = 0;
	while (path[i] != '\0')
		i++;
	if ((ft_strncmp(path, "/\0", 2) == 0) || (path[--i] == '/'))
	{
		ret = ft_strjoin(path, dir);
		return (ret);
	}
	meme = ft_strjoin(path, "/");
	ret = ft_strjoin(meme, dir);
	free(meme);
	return (ret);
}

void				sub_loop(t_list *list, char *memstr, t_parse *parse)
{
	char			*str;

	while (list != NULL)
	{
		if ((ft_strcmp(list->dir_mem.d_name, ".") != 0) &&
		(ft_strcmp(list->dir_mem.d_name, "..") != 0) &&
		(S_ISDIR(list->st.st_mode)))
		{
			str = join_path(memstr, list->dir_mem.d_name);
			ft_putstr("\n");
			ft_putstr(str);
			ft_putstr(":\n");
			if (main_loop(str, parse) != 0)
				print_error(str);
			free(str);
		}
		list = list->next;
	}
}

int					main_loop(char *memstr, t_parse *parse)
{
	struct dirent	*ret;
	t_list			*list;
	DIR				*dir;
	char			buff[1];

	ret = NULL;
	list = NULL;
	readlink(memstr, buff, sizeof(buff));
	if ((!(errno == 22) && (parse->l == 1)) || (dir = opendir(memstr)) == NULL)
		return (-1);
	while ((ret = readdir(dir)) != NULL)
	{
		if ((parse->a == 1) || (ft_strncmp(ret->d_name, ".", 1)))
		{
			if (list == NULL)
				list = initlist(ret, list, memstr, parse);
			else
				list = newnode(ret, list, memstr, parse);
		}
	}
	print_list(list, parse, memstr, 0);
	if (parse->rec)
		sub_loop(list, memstr, parse);
	flush_dir(list, dir);
	return (0);
}

void				test_file(char *file, t_parse *parse)
{
	t_list	*list;

	list = NULL;
	if (errno == 20 || errno == 0)
	{
		list = initlist(NULL, list, file, parse);
		print_list(list, parse, file, 1);
		free_list(list);
	}
	else
		print_error(file);
}

int					main(int argc, char **argv)
{
	t_parse			*parse;
	int				i;

	i = 0;
	parse = init_parse();
	if ((argv = parser(argc, argv, parse)) == NULL)
	{
		ft_putstr("usage: ls [-Ralrt] [file ...]\n");
		return (-1);
	}
	while (argv[i] != NULL)
	{
		parse->arg = i;
		if (main_loop(argv[i], parse) != 0)
		{
			test_file(argv[i], parse);
		}
		i++;
	}
	free(parse);
	return (0);
}
