/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 23:49:32 by nhaquet           #+#    #+#             */
/*   Updated: 2016/04/14 20:24:41 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "libft/libft.h"
#include "ft_ls.h"

void initlist(char *str, t_list *list)
{
	list = malloc(sizeof(t_list));
	if (list != NULL)
	{
		list->str = str;
		list->next = NULL;
		list->next = NULL;
	}
}

void newnode(char *str, t_list *list)
{
	t_list	*node;

	if(list == NULL)
		initlist(str, list);
	else
	{
		node = malloc(sizeof(t_list));
		if(node != NULL)
		{
			node->str = str;
			node->next = list;
			node->prev = NULL;
			list->prev = node;
		}
	}
}

int	main(int argc,char **argv)
{
	DIR		*dir;
	struct	dirent	*ret;
	char	*mem1;
	t_list	*list;
	int		stop;

	ret = NULL;
	mem1 = ".";
	list = NULL;
	stop = 0;
	if (argc > 1)
		mem1 = argv[1];
	dir = opendir(mem1);
	while (stop == 0)
	{
		ret = readdir(dir);
		newnode(ret->d_name, list);
		if (ret == NULL && errno == 0)
			stop = 1;
	}
	while (list->next != NULL) {
		ft_putstr("lol\n");
		write(1, list->str, ft_strlen(list->str));
		list = list->next;
	}
	return (0);
}
