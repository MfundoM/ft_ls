/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 15:15:38 by mmthethw          #+#    #+#             */
/*   Updated: 2017/09/15 15:15:48 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long n, int b, int lowup)
{
	char				*s;
	unsigned long long	tmp;
	int					length;

	lowup = (lowup) ? 'A' - 10 : 'a' - 10;
	length = 1;
	tmp = n;
	while (tmp /= b)
		++length;
	if (!(s = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	s[length] = '\0';
	while (length--)
	{
		s[length] = (n % b < 10) ? n % b + '0' : n % b + lowup;
		n /= b;
	}
	return (s);
}
