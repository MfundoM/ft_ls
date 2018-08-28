/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 08:51:18 by mmthethw          #+#    #+#             */
/*   Updated: 2017/06/08 08:24:21 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	if (*little == '\0' && *big == '\0')
		return ((char*)big);
	while (big[a])
	{
		b = a;
		c = 0;
		if (little[c] == '\0')
			return ((char*)(&big[a]));
		while (big[b] && little[c] && big[b] == little[c])
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
