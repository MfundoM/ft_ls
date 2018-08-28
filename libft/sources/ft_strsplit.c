/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:05:55 by mmthethw          #+#    #+#             */
/*   Updated: 2017/06/16 08:15:14 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**str;
	int		nbr_words;
	int		word_len;

	i = 0;
	nbr_words = ft_wordcount((char*)s, c);
	if ((str = (char**)malloc(sizeof(char*) * (nbr_words + 1))))
	{
		word_len = 0;
		while (i < nbr_words)
		{
			while (*s == c)
				s++;
			while (*s != c && *s)
			{
				word_len++;
				s++;
			}
			str[i++] = ft_strsub(s - word_len, 0, word_len);
			word_len = 0;
		}
		str[i] = NULL;
	}
	return (str);
}
