/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:41:42 by mmthethw          #+#    #+#             */
/*   Updated: 2017/06/07 08:10:30 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*dest;
	const unsigned char	*src;

	dest = (unsigned char*)s1;
	src = (unsigned char*)s2;
	while (n > 0)
	{
		if (*dest != *src)
			return (*dest - *src);
		else
		{
			dest++;
			src++;
			n--;
		}
	}
	return (0);
}
