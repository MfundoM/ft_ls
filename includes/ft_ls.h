/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 12:38:15 by mmthethw          #+#    #+#             */
/*   Updated: 2017/09/18 10:12:44 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <limits.h>
# include <sys/ioctl.h>

enum {ERRNO, USAGE, MALL_ERR};

# define LS_A	1
# define LS_L	2
# define LS_RR	4
# define LS_R	8
# define LS_T	16
# define LS_D	32
# define LS_G	64
# define LS_ONE 128

# define FT_RED		"\033[31m"
# define FT_CYAN	"\033[36m\033[1m"
# define FT_EOC		"\033[37m\033[0m"

# define TRUE 1
# define FALSE 0

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct			s_data
{
	mode_t				mode;
	nlink_t				st_nlink;
	uid_t				st_uid;
	gid_t				st_gid;
	off_t				size;
	time_t				time;
	long				ntime;
	char				*name;
	char				full_path[PATH_MAX];
	struct s_data		*next;
	t_list				list;
}						t_data;

int						ft_add_new_file(char path[PATH_MAX], char *name,
															t_data **list);

int						ft_display_all(t_data *begin, int flags, int first,
																	int n);

int						ft_display_detailed_list(t_data *lst, int flags);

int						ft_lst_block_len(t_data *lst, int *total);

int						ft_display_list(t_data **lst, int flags);

void					ft_display_name(t_data *l, int flags);

int						ft_display_list_items(t_data *file, int flags);

t_data					*ft_init_files_list(char **names_list, int argcc,
																int first);

int						ft_parsing(int argcc, char **argvv, int *flags);

int						ft_parse_options(char *s, int *flags);

int						ft_ls_error(char *s, int error);

t_data					*ft_reverse_lst(t_data *lst);

int						ft_sort_list(t_data **begin, short flags);

t_data					*ft_lst_swap(t_data *p1, t_data *p2);

#endif
