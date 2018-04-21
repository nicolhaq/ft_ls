/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:04:15 by nhaquet           #+#    #+#             */
/*   Updated: 2018/02/02 17:11:14 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_list			*insert_in_list(t_list *list, t_list *node, t_parse *parse)
{
	t_list		*mem;

	mem = list;
	while ((list->next != NULL) && ((ft_strcmp(list->next->dir_mem.d_name
	, node->dir_mem.d_name) * parse->rev) < 0))
		list = list->next;
	if ((list == mem) && ((ft_strcmp(list->dir_mem.d_name
	, node->dir_mem.d_name) * parse->rev) > 0))
	{
		node->next = list;
		mem = node;
	}
	else if (list->next == NULL)
	{
		node->next = NULL;
		list->next = node;
	}
	else
	{
		node->next = list->next;
		list->next = node;
	}
	return (mem);
}

t_list			*sub_time_sort(t_list *list, t_list *node, t_parse *parse)
{
	while ((list->next != NULL) &&
	(((node->st.st_mtime - list->next->st.st_mtime) * parse->rev) < 0))
		list = list->next;
	if ((list->next != NULL) && (node->st.st_mtime == list->next->st.st_mtime))
	{
		while ((list->next != NULL)
		&& ((node->st.st_mtime == list->next->st.st_mtime)
		&& ((ft_strcmp(list->next->dir_mem.d_name, node->dir_mem.d_name)
		* parse->rev) < 0)))
			list = list->next;
	}
	return (list);
}

t_list			*insert_in_list_by_time(t_list *list,
t_list *node, t_parse *parse)
{
	t_list		*mem;

	mem = list;
	list = sub_time_sort(list, node, parse);
	if ((list == mem)
	&& ((((node->st.st_mtime - list->st.st_mtime) * parse->rev) > 0)
	|| ((parse->rev == -1) && node->st.st_mtime == list->st.st_mtime)))
	{
		node->next = list;
		mem = node;
	}
	else if (list->next == NULL)
	{
		node->next = NULL;
		list->next = node;
	}
	else
	{
		node->next = list->next;
		list->next = node;
	}
	return (mem);
}
