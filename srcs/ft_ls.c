/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 11:28:04 by mmthethw          #+#    #+#             */
/*   Updated: 2017/09/18 09:27:56 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*ft_init_files_list(char **names_list, int ac, int first)
{
	t_data	*begin;
	int		i;

	begin = NULL;
	(!ac) ? ft_add_new_file("", ".", &begin) : 0;
	i = -1;
	while (++i < ac)
		if (ft_add_new_file("", names_list[i], &begin) == -1 && first)
			ft_ls_error(names_list[i], ERRNO);
	return (begin);
}

int		main(int ac, char **av)
{
	int			i;
	int			flags;
	t_data		*file_lst;
	int			no_files;

	if ((i = ft_parsing(ac, av, &flags)) == -1)
		return (1);
	av = av + i;
	ac = ac - i;
	file_lst = ft_init_files_list(av, ac, 1);
	no_files = (!file_lst ? 1 : 0);
	ft_display_all(file_lst, flags, (!no_files ? 1 : 0), ac);
	free(file_lst);
	return (0);
}
