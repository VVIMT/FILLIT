/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:55:13 by becorbel          #+#    #+#             */
/*   Updated: 2016/12/02 17:55:14 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

long	ft_print(char **data)
{
	long i;
	long j;

	i = 0;
	while (data[i][0] && data[i][0] != '#')
	{
		j = 0;
		while (data[i][j] && data[i][j] != '#')
		{
			ft_putchar(data[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
