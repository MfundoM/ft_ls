/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:29:51 by mmthethw          #+#    #+#             */
/*   Updated: 2017/09/15 17:04:09 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_data	*ft_read_folder(char path[PATH_MAX], char *name, int options)
{
	t_data			*begin;
	DIR				*folder;
	struct dirent	*entry;

	begin = NULL;
	if (!(folder = opendir(path)))
		ft_ls_error(name, 0);
	else if (!(options & LS_D))
	{
		while ((entry = readdir(folder)))
			if (entry->d_name[0] != '.' || (options & LS_A))
				ft_add_new_file(path, entry->d_name, &begin);
	}
	else
		ft_add_new_file(path, ".", &begin);
	if (folder)
		closedir(folder);
	return (begin);
}

static void		ft_display_full_path(char *full_path, int number, int *first)
{
	if (number != 0 && number != 1)
	{
		if (*first)
		{
			ft_putstr(full_path);
			ft_putstr(":");
			ft_putchar('\n');
		}
		else
		{
			ft_putchar('\n');
			ft_putstr(full_path);
			ft_putstr(":");
			ft_putchar('\n');
		}
	}
}

int				ft_display_all(t_data *begin, int flags, int first, int n)
{
	t_data			*file;

	file = begin;
	if (!(flags & LS_RR) && !first)
		return (1);
	while (file)
	{
		if (S_ISDIR(file->mode) && (first || (ft_strcmp(file->name, ".")
			&& ft_strcmp(file->name, ".."))))
		{
			ft_display_full_path(file->full_path, n, &first);
			begin = ft_read_folder(file->full_path, file->name, flags);
			if (begin)
			{
				ft_display_list(&begin, flags);
				ft_display_all(begin, flags, 0, -1);
				free(begin);
			}
		}
		file = file->next;
	}
	return (1);
}
