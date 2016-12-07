/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivimont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:56:35 by vivimont          #+#    #+#             */
/*   Updated: 2016/01/07 21:47:09 by vivimont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char	const	*x;
	unsigned char			*y;

	x = src;
	y = dst;
	i = 0;
	while (i < n)
	{
		y[i] = x[i];
		if (x[i] == (unsigned char)c)
			return (y + i + 1);
		i++;
	}
	return (NULL);
}
