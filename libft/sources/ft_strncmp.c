/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:48:18 by mmthethw          #+#    #+#             */
/*   Updated: 2017/06/07 13:17:10 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char*)s1;
	src = (unsigned char*)s2;
	i = 0;
	while ((dst[i] || src[i]) && (i < n))
	{
		if (dst[i] < src[i])
			return (dst[i] - src[i]);
		if (dst[i] > src[i])
			return (dst[i] - src[i]);
		i++;
	}
	return (0);
}
