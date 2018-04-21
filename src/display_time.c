/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:12:40 by nhaquet           #+#    #+#             */
/*   Updated: 2018/03/23 19:25:10 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"
#include <time.h>

char		*get_year(void)
{
	char	*ttime;
	char	**dtime;
	char	**ret;
	char	*str;
	time_t	ts;

	time(&ts);
	ttime = ctime(&ts);
	dtime = ft_strsplit(ttime, ' ');
	ret = ft_strsplit(dtime[4], '\n');
	ft_freetab((void**)dtime);
	str = ft_strdup(ret[0]);
	ft_freetab((void**)ret);
	return (str);
}

void		print_dtime(char **dtime, char *str)
{
	ft_strcat(str, dtime[1]);
	ft_strcat(str, ((ft_strlen(dtime[2]) > 1) ? " " : "  "));
	ft_strcat(str, dtime[2]);
	ft_strcat(str, " ");
}

void		print_ret(char **ret, char *str)
{
	ft_strcat(str, " ");
	ft_strcat(str, ret[0]);
}

void		print_htime(char **htime, char *str)
{
	ft_strcat(str, htime[0]);
	ft_strcat(str, ":");
	ft_strcat(str, htime[1]);
}

void		display_time(t_list *list, char *str)
{
	char	*ttime;
	char	**dtime;
	char	**htime;
	char	**ret;
	char	*str2;

	ttime = ctime(&list->st.st_mtime);
	dtime = ft_strsplit(ttime, ' ');
	htime = ft_strsplit(dtime[3], ':');
	ret = ft_strsplit(dtime[4], '\n');
	str2 = get_year();
	print_dtime(dtime, str);
	if (!(strcmp(str2, ret[0]) > 1))
	{
		print_htime(htime, str);
	}
	else
	{
		print_ret(ret, str);
	}
	ft_strcat(str, " ");
	free(str2);
	ft_freetab((void**)dtime);
	ft_freetab((void**)htime);
	ft_freetab((void**)ret);
}
