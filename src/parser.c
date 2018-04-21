/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 23:49:32 by nhaquet           #+#    #+#             */
/*   Updated: 2018/03/16 17:51:18 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_parse		*init_parse(void)
{
	t_parse	*parse;

	parse = (t_parse*)malloc(sizeof(t_parse));
	parse->rec = 0;
	parse->a = 0;
	parse->l = 0;
	parse->rev = 1;
	parse->t = 0;
	parse->arg = 0;
	return (parse);
}

char		sub_parser_arg(char *str, t_parse *parse)
{
	int		y;

	y = 1;
	while (str[y] != '\0')
	{
		if (str[y] == 'R')
			parse->rec = 1;
		else if (str[y] == 'r')
			parse->rev = -1;
		else if (str[y] == 'a')
			parse->a = 1;
		else if (str[y] == 't')
			parse->t = 1;
		else if (str[y] == 'l')
			parse->l = 1;
		else
			return (str[y]);
		y++;
	}
	return (0);
}

void		sub_parser(char **argv, int *i)
{
	i[2] = 1;
	argv[i[1]] = argv[i[0]];
	i[1]++;
}

int			test_flag(char **argv, int *i, t_parse *parse)
{
	char	ret;

	ret = 0;
	if (!(ft_strcmp(argv[i[0]], "--")))
		i[2] = 1;
	else if (!(ft_strncmp(argv[i[0]], "-", 1)) &&
	(ft_strlen(argv[i[0]]) > 1) && !i[2])
	{
		ret = sub_parser_arg(argv[i[0]], parse);
		if (ret != 0)
		{
			ft_putstr("ls: illegal option -- ");
			ft_putchar(ret);
			ft_putstr("\n");
			return (-1);
		}
	}
	else
		sub_parser(argv, i);
	return (0);
}

char		**parser(int argc, char **argv, t_parse *parse)
{
	int		i[3];

	i[0] = 1;
	i[1] = 0;
	i[2] = 0;
	argv[0] = ".\0";
	while (i[0] < argc)
	{
		if ((test_flag(argv, i, parse)) == -1)
			return (NULL);
		i[0]++;
	}
	if (i[1] == 0)
		i[1]++;
	argv[i[1]] = NULL;
	return (argv);
}
