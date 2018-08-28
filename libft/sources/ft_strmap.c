/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 21:36:55 by mmthethw          #+#    #+#             */
/*   Updated: 2017/06/07 22:44:01 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (0);
	i = 0;
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	while (*s)
	{
		str[i] = f(*s++);
		i++;
	}
	str[i] = '\0';
	return (str);
}
