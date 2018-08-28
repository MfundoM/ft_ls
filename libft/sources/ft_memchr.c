/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 21:32:59 by mmthethw          #+#    #+#             */
/*   Updated: 2017/06/10 12:55:12 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	unsigned char cast;

	cast = (unsigned char)c;
	str = (unsigned char*)s;
	while (n > 0)
	{
		if (*str != cast)
			str++;
		else
			return (str);
		n--;
	}
	return (0);
}
