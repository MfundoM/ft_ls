/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 15:14:32 by mmthethw          #+#    #+#             */
/*   Updated: 2017/09/15 15:14:37 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr(wchar_t *s)
{
	int		len;

	len = ft_wstrlen((unsigned *)s);
	(!len) ? write(1, "(null)", 6) : write(1, s, len);
	return ((!len) ? 6 : len);
}
