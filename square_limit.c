/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_limit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:56:04 by becorbel          #+#    #+#             */
/*   Updated: 2016/12/02 17:56:05 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	square_limit(char **grid, char c, long sq)
{
	long i;

	i = sq;
	while (i >= 0)
		grid[sq][i--] = c;
	i = sq;
	while (i >= 0)
		grid[i--][sq] = c;
}
