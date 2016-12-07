/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:21:56 by vinvimo           #+#    #+#             */
/*   Updated: 2016/12/07 20:34:16 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	limit(t_struct *v, t_tetriminos **t)
{
	int	c;

	c = 0;
	while (c <= v->n_tetri)
	{
		if (v->sq >= t[c]->l && v->sq >= t[c]->h)
			t[c]->limit = (v->sq - t[c]->l + 1) * (v->sq - t[c]->h + 1) + 1;
		else
			return (0);
		c++;
	}
	return (1);
}

int	place(int k, t_struct *v, t_tetriminos **t, char **grid)
{
	reset(grid, v->sq);
	square_limit(grid, '#', v->sq);
	if (!(limit(v, t)))
		return (0);
	while (k <= v->n_tetri)
	{
		while (t[k]->tetri_pos <= t[k]->limit
				&& !(check(v->sq, t[k]->tetri_pos, t[k], grid)))
			(t[k]->tetri_pos)++;
		if (t[k]->tetri_pos > t[k]->limit)
		{
			if (k == 0)
				return (0);
			t[k]->tetri_pos = 0;
			rm(v->sq, t[k - 1]->tetri_pos, t[k - 1], grid);
			(t[--k]->tetri_pos)++;
		}
		else
			stack(t[k++], grid);
	}
	ft_print(grid);
	return (1);
}

int	one(long sq, t_struct *v, t_tetriminos *t, char **grid)
{
	int				c;
	t_tetriminos	*tmp;
	t_tetriminos	**lst;

	if (!(lst = (t_tetriminos**)malloc(sizeof(*lst) * (v->n_tetri + 1))))
		return (0);
	tmp = t;
	c = 0;
	while (tmp)
	{
		lst[c++] = tmp;
		tmp = tmp->next;
	}
	v->sq = sq;
	c = 0;
	while (c <= v->n_tetri)
		lst[c++]->tetri_pos = 0;
	if (!(place(0, v, lst, grid)))
		return (one(sq + 1, v, t, grid));
	return (0);
}
