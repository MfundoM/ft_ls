/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:50:10 by mmthethw          #+#    #+#             */
/*   Updated: 2017/05/31 13:58:51 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = 0;
	while (big[a] != '\0')
	{
		b = a;
		c = 0;
		if (little[c] == '\0')
			return ((char*)(&big[a]));
		while (big[b] && little[c] && big[b] == little[c] && b <= len)
		{
			b++;
			c++;
			if (little[c] == '\0')
				return ((char*)(&big[a]));
		}
		a++;
	}
	return (0);
}
