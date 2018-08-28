/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_detailed_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:11:45 by mmthethw          #+#    #+#             */
/*   Updated: 2017/09/18 09:34:04 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_display_detailed_list(t_data *lst, int flags)
{
	while (lst)
	{
		ft_display_list_items(lst, flags);
		ft_putchar('\n');
		lst = lst->next;
	}
	return (1);
}
