/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:27:45 by vinvimo           #+#    #+#             */
/*   Updated: 2016/12/05 18:38:02 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	rm(long sq, long pos, t_tetriminos *t, char **grid)
{
	if (sq >= t->h && sq >= t->l)
		t->i = pos / (sq - t->l + 1);
	else
		t->i = 0;
	if (sq >= t->l)
		t->j = pos % (sq - t->l + 1);
	else
		t->j = 0;
	grid[t->i + t->coorx0][t->j + t->coory0] = 46;
	grid[t->i + t->coorx1][t->j + t->coory1] = 46;
	grid[t->i + t->coorx2][t->j + t->coory2] = 46;
	grid[t->i + t->coorx3][t->j + t->coory3] = 46;
}
