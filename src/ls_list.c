/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:53:31 by nhaquet           #+#    #+#             */
/*   Updated: 2018/03/16 19:01:21 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

struct stat		make_stat(char *str, t_parse *parse)
{
	struct stat	stt;

	if (parse->l == 0)
		stat(str, &stt);
	else
		lstat(str, &stt);
	return (stt);
}

t_list			*initlist(struct dirent *dirnt, t_list *list,
				char *memstr, t_parse *parse)
{
	struct stat	stt;
	char		*str;

	str = memstr;
	if (dirnt != NULL)
		str = join_path(memstr, dirnt->d_name);
	stt = make_stat(str, parse);
	list = (t_list *)malloc(sizeof(t_list));
	if (dirnt != NULL)
		free(str);
	if (list != NULL)
	{
		if (dirnt != NULL)
			list->dir_mem = *dirnt;
		list->st = stt;
		list->next = NULL;
		return (list);
	}
	return (NULL);
}

t_list			*newnode(struct dirent *dirnt,
				t_list *list, char *memstr, t_parse *parse)
{
	t_list		*node;
	struct stat	stt;

	memstr = join_path(memstr, dirnt->d_name);
	stt = make_stat(memstr, parse);
	free(memstr);
	if (list == NULL)
	{
		return (list);
	}
	else
	{
		node = (t_list *)malloc(sizeof(t_list));
		node->dir_mem = *dirnt;
		node->st = stt;
		if (node != NULL)
		{
			if (parse->t == 1)
				list = insert_in_list_by_time(list, node, parse);
			else
				list = insert_in_list(list, node, parse);
		}
	}
	return (list);
}

void			free_list(t_list *list)
{
	t_list		*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
