/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:08:11 by mmthethw          #+#    #+#             */
/*   Updated: 2017/06/12 09:29:58 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(char *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	if (s)
	{
		while (s[i] == c)
			s++;
		while (s[i])
		{
			if (i == 0 && s[i] != c)
				word++;
			else if (s[i] != c && s[i - 1] == c)
				word++;
			i++;
		}
	}
	return (word);
}
