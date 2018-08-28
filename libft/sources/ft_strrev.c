/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:21:31 by mmthethw          #+#    #+#             */
/*   Updated: 2017/06/09 13:36:26 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	res;

	i = 0;
	len = ft_strlen(str);
	while (len - 1 > i)
	{
		res = str[i];
		str[i] = str[len - 1];
		str[len - 1] = res;
		len--;
		i++;
	}
	return (str);
}
