/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 15:18:30 by mmthethw          #+#    #+#             */
/*   Updated: 2017/09/15 15:18:33 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrsub(wchar_t *s, unsigned start, unsigned len)
{
	wchar_t		*str;
	unsigned	i;

	if (!(str = ft_memalloc(sizeof(wchar_t) * (len + 1))))
		return (NULL);
	i = 0;
	while (ft_wcharlen(s[i + start]) < len)
	{
		str[i] = s[i + start];
		i += ft_wcharlen(str[i]);
	}
	str[i] = '\0';
	return (str);
}
