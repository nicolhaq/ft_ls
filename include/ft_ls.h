/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:05:22 by nhaquet           #+#    #+#             */
/*   Updated: 2018/04/12 13:44:11 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <stdio.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include "../libft/libft.h"

typedef struct		s_list
{
	struct dirent	dir_mem;
	struct stat		st;
	struct s_list	*next;
}					t_list;

typedef struct		s_parse
{
	int				arg;
	int				rec;
	int				a;
	int				rev;
	int				t;
	int				l;
}					t_parse;

char				*join_path(char *path, char *dir);
void				sub_loop(t_list *list, char *memstr, t_parse *parse);
int					main_loop(char *memstr, t_parse *parse);
t_list				*initlist(struct dirent *dirnt, t_list *list,
						char *memstr, t_parse *parse);
t_list				*newnode(struct dirent *dirnt, t_list *list,
						char *memstr, t_parse *parse);
void				free_list(t_list *list);
void				print_list(t_list *list, t_parse *parse, char *memstr,
						int mode);
t_parse				*init_parse();
char				**parser(int argc, char **argv, t_parse *parse);
char				sub_parser_arg(char *str, t_parse *parse);
t_list				*insert_in_list_by_time(t_list *list, t_list *node,
						t_parse *parse);
t_list				*insert_in_list(t_list *list, t_list *node, t_parse *parse);
void				put_buffer(int nb1, int nb2, char *str);
void				display_type(t_list *list, char *str);
void				display_fr(t_list *list, char *str);
void				display_nm(t_list *list, int name_len, char *str);
void				display_gr(t_list *list, int grp_len, char *str);
void				display_link(t_list *list, char *memstr, int mode);
void				display_time(t_list *list, char *str);
void				display_link_nb(t_list *list, int link, char *str);
void				display_size(t_list *list, int size, char *str);
void				display_blocks(int blocks);
void				display_dir_name(char *memstr);
void				print_all(t_list *list, int *size, char *str);
void				print_error(char *file);
void				flush_dir(t_list *list, DIR *dir);
void				endline(t_list *list, char *memstr, int mode,
						t_parse *parse);
int					minmaj(int min, int maj);
void				display_minmaj(t_list *list, int size, char *str);

#endif
