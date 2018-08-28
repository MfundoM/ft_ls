/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:18:42 by mmthethw          #+#    #+#             */
/*   Updated: 2017/09/18 09:35:01 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_basic_list(t_data *lst, int flags)
{
	while (lst)
	{
		ft_display_name(lst, flags);
		ft_putchar('\n');
		lst = lst->next;
	}
	return (1);
}

int			ft_display_list(t_data **lst, int flags)
{
	ft_sort_list(lst, flags);
	if (!(flags & LS_L))
		ft_basic_list(*lst, flags);
	else
		ft_display_detailed_list(*lst, flags);
	return (1);
}

void		ft_display_name(t_data *l, int flags)
{
	if (flags & LS_G)
	{
		if (S_ISDIR(l->mode))
			ft_printf("%{cyan}%s%{eoc}", l->name);
		else
			ft_printf((S_IXUSR & l->mode) ? "%{red}%s%{eoc}" : "%s", l->name);
	}
	else
		ft_putstr(l->name);
}
