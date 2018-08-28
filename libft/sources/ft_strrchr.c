/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:02:19 by mmthethw          #+#    #+#             */
/*   Updated: 2017/06/03 19:56:47 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*var;
	int		n;

	n = ft_strlen(s);
	var = 0;
	while (n >= 0)
	{
		if (*s == (char)c)
			var = (char*)s;
		s++;
		n--;
	}
	return (var);
}
