/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:05:03 by mmthethw          #+#    #+#             */
/*   Updated: 2017/06/01 19:11:08 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char*)s1;
	src = (unsigned char*)s2;
	i = 0;
	while (dst[i] || src[i])
	{
		if (dst[i] < src[i])
			return (dst[i] - src[i]);
		if (dst[i] > src[i])
			return (dst[i] - src[i]);
		i++;
	}
	return (0);
}
