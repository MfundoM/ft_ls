/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_iterms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:54:38 by mmthethw          #+#    #+#             */
/*   Updated: 2017/09/18 09:34:14 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		ft_get_file_type(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

static void		ft_display_chmod(char chmod[12], int mode)
{
	chmod[0] = ft_get_file_type(mode);
	chmod[1] = (S_IRUSR & mode) ? 'r' : '-';
	chmod[2] = (S_IWUSR & mode) ? 'w' : '-';
	chmod[3] = (S_IXUSR & mode) ? 'x' : '-';
	chmod[4] = (S_IRGRP & mode) ? 'r' : '-';
	chmod[5] = (S_IWGRP & mode) ? 'w' : '-';
	chmod[6] = (S_IXGRP & mode) ? 'x' : '-';
	chmod[7] = (S_IROTH & mode) ? 'r' : '-';
	chmod[8] = (S_IWOTH & mode) ? 'w' : '-';
	chmod[9] = (S_IXOTH & mode) ? 'x' : '-';
	chmod[10] = '\0';
	ft_putstr(chmod);
}

static void		ft_display_time(t_data *file)
{
	time_t	today;
	char	*s;

	time(&today);
	s = ctime(&(file->time)) + 4;
	ft_printf(" %.12s ", s);
}

int				ft_display_list_items(t_data *file, int flags)
{
	char	str[12];
	char	buf[NAME_MAX + 1];

	ft_display_chmod(str, file->mode);
	ft_printf("%4d ", file->st_nlink);
	ft_printf("%5s ", getpwuid(file->st_uid)->pw_name);
	ft_printf("%9s", getgrgid(file->st_gid)->gr_name);
	ft_printf("%7ld", file->size);
	ft_display_time(file);
	if (str[0] != 'l')
		ft_display_name(file, flags);
	else
	{
		ft_bzero(buf, NAME_MAX + 1);
		readlink(file->full_path, buf, NAME_MAX);
		ft_printf("%s -> %s", file->name, buf);
	}
	return (1);
}
