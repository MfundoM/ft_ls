/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 07:16:11 by mmthethw          #+#    #+#             */
/*   Updated: 2017/06/06 14:35:09 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	cast;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	cast = (unsigned char)c;
	while (n > 0)
	{
		*s1 = *s2;
		if (*s1 == cast)
		{
			s1++;
			s2++;
			return (s1);
		}
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (NULL);
	return (0);
}
