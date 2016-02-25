/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 23:49:32 by nhaquet           #+#    #+#             */
/*   Updated: 2016/02/25 00:30:58 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include<errno.h>

int	strsize (char * str)
{
	int i;

	i = 0;
	while(str[i] > 0)
	{
		i++;
	}
	return (i);
}

int	main(int argc,char **argv)
{
	DIR		*dir;
	struct	dirent	*ret;
	char	*mem1;

	ret = NULL;
	mem1 = ".";
	if (argc > 1)
		mem1 = argv[1];

	dir = opendir(mem1);
	while (1)
	{
		ret = readdir(dir);
		write(1,ret->d_name,strsize(ret->d_name));
		write(1, "\n", 1);
		if (ret == NULL && errno == 0) {
			return(0);
		}
	}
	return 0;
}
