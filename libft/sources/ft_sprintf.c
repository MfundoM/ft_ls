/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:23:22 by mmthethw          #+#    #+#             */
/*   Updated: 2017/09/15 17:01:32 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sprintf(char *buf, const char *format, ...)
{
	int			n;
	va_list		ap;

	va_start(ap, format);
	n = vsprintf(buf, format, ap);
	va_end(ap);
	return (n);
}
