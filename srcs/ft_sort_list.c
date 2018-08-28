/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 12:22:26 by mmthethw          #+#    #+#             */
/*   Updated: 2017/09/18 09:53:40 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data			*ft_reverse_lst(t_data *lst)
{
	t_data *a;
	t_data *b;
	t_data *c;

	a = NULL;
	b = lst;
	c = (lst)->next;
	while (b)
	{
		c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	return (a);
}

static t_data	*ft_lst_sort_ascii(t_data *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
		lst = ft_lst_swap(lst, lst->next);
	lst->next = ft_lst_sort_ascii(lst->next);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
	{
		lst = ft_lst_swap(lst, lst->next);
		lst->next = ft_lst_sort_ascii(lst->next);
	}
	return (lst);
}

static t_data	*ft_lst_sort_time(t_data *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && (lst->time < lst->next->time))
		lst = ft_lst_swap(lst, lst->next);
	else if (lst->next && lst->time == lst->next->time)
		if (lst->next && (lst->ntime < lst->next->ntime))
			lst = ft_lst_swap(lst, lst->next);
	lst->next = ft_lst_sort_time(lst->next);
	if (lst->next && (lst->time < lst->next->time))
	{
		lst = ft_lst_swap(lst, lst->next);
		lst->next = ft_lst_sort_time(lst->next);
	}
	else if (lst->next && lst->time == lst->next->time)
	{
		if (lst->next && (lst->ntime < lst->next->ntime))
		{
			lst = ft_lst_swap(lst, lst->next);
			lst->next = ft_lst_sort_time(lst->next);
		}
	}
	return (lst);
}

int				ft_sort_list(t_data **begin, short flags)
{
	*begin = ft_lst_sort_ascii(*begin);
	if (flags & LS_T)
		*begin = ft_lst_sort_time(*begin);
	if (flags & LS_R)
		*begin = ft_reverse_lst(*begin);
	return (1);
}
