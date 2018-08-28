/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:02:28 by mmthethw          #+#    #+#             */
/*   Updated: 2017/06/12 14:51:30 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	count;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	count = 0;
	if (dst_len >= size)
		return (src_len + size);
	while (dest[count] != '\0' && count < size - 1)
		count++;
	while (*src != '\0' && count < size - 1)
	{
		dest[count] = *src;
		count++;
		src++;
	}
	dest[count] = '\0';
	return (dst_len + src_len);
}
