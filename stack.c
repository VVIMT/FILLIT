/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:27:25 by vinvimo           #+#    #+#             */
/*   Updated: 2016/12/05 18:37:36 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	stack(t_tetriminos *t, char **grid)
{
	grid[t->i + t->coorx0][t->j + t->coory0] = t->tetri[t->coorx0][t->coory0];
	grid[t->i + t->coorx1][t->j + t->coory1] = t->tetri[t->coorx1][t->coory1];
	grid[t->i + t->coorx2][t->j + t->coory2] = t->tetri[t->coorx2][t->coory2];
	grid[t->i + t->coorx3][t->j + t->coory3] = t->tetri[t->coorx3][t->coory3];
}

int		check(long sq, long pos, t_tetriminos *t, char **grid)
{
	if (sq >= t->h && sq >= t->l)
		t->i = pos / (sq - t->l + 1);
	else
		t->i = 0;
	if (sq >= t->l)
		t->j = pos % (sq - t->l + 1);
	else
		t->j = 0;
	if (grid[t->i + t->coorx0][t->j + t->coory0] != 46 || t->i >= sq)
		return (0);
	if (grid[t->i + t->coorx1][t->j + t->coory1] != 46 || t->i >= sq)
		return (0);
	if (grid[t->i + t->coorx2][t->j + t->coory2] != 46 || t->i >= sq)
		return (0);
	if (grid[t->i + t->coorx3][t->j + t->coory3] != 46 || t->i >= sq)
		return (0);
	return (1);
}
