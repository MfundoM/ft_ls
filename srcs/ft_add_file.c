/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:46:37 by mmthethw          #+#    #+#             */
/*   Updated: 2017/09/18 09:21:57 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_get_full_path(char path[PATH_MAX], char *name,
								char full_path[PATH_MAX])
{
	int	i;

	i = -1;
	while (path[++i])
		full_path[i] = path[i];
	if (i && i < PATH_MAX)
		if (!(path[0] == '/' && path[1] == '\0'))
			full_path[i++] = '/';
	while (*name && i < PATH_MAX)
		full_path[i++] = *name++;
	if (i < PATH_MAX)
		full_path[i] = '\0';
	else
		errno = ENAMETOOLONG;
	return ((i < PATH_MAX) ? 1 : 0);
}

static t_data	*ft_new_file(char path[PATH_MAX], char *name, t_stat *stat)
{
	t_data	*new;

	if (!(new = (t_data*)ft_memalloc(sizeof(t_data)))
	|| (!(new->name = ft_strdup(name))))
		ft_ls_error(NULL, 2);
	new->mode = stat->st_mode;
	new->st_nlink = stat->st_nlink;
	new->st_uid = stat->st_uid;
	new->st_gid = stat->st_gid;
	new->size = stat->st_size;
	new->time = stat->st_mtime;
	new->ntime = stat->st_mtime;
	ft_get_full_path(path, name, new->full_path);
	new->next = NULL;
	return (new);
}

int				ft_add_new_file(char path[PATH_MAX], char *name, t_data **lst)
{
	char		full_path[PATH_MAX];
	t_stat		stat;

	if (!(ft_get_full_path(path, name, full_path)))
	{
		ft_ls_error(name, 1);
		return (-1);
	}
	if (lstat(full_path, &stat) == -1)
		return (-1);
	if (!*lst)
		*lst = ft_new_file(path, name, &stat);
	else
	{
		while ((*lst)->next)
			lst = &((*lst)->next);
		(*lst)->next = ft_new_file(path, name, &stat);
	}
	return (1);
}
