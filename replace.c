/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:29:58 by vinvimo           #+#    #+#             */
/*   Updated: 2016/12/02 19:30:03 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	coor(int count, int x, int y, t_tetriminos *t)
{
	if (count == 0)
	{
		t->coorx0 = x;
		t->coory0 = y;
	}
	if (count == 1)
	{
		t->coorx1 = x;
		t->coory1 = y;
	}
	if (count == 2)
	{
		t->coorx2 = x;
		t->coory2 = y;
	}
	if (count == 3)
	{
		t->coorx3 = x;
		t->coory3 = y;
	}
}

char	**replace(int i, int j, char **tetrim, t_tetriminos *t)
{
	char	**tetri_copy;
	int		x;
	int		y;
	int		count;

	count = 0;
	x = -1;
	tetri_copy = create_tab(4, 4, 0, NULL);
	while (i + ++x < 4)
	{
		y = -1;
		while (tetrim[i][j + ++y])
		{
			tetri_copy[x][y] = tetrim[i + x][j + y];
			if (tetri_copy[x][y] >= 'A' && tetri_copy[x][y] <= 'Z')
			{
				coor(count, x, y, t);
				count++;
			}
		}
		tetri_copy[x][y] = '\0';
	}
	while (x < 4)
		ft_bzero(tetri_copy[x++], 4);
	return (tetri_copy);
}
