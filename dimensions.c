/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:26:43 by vinvimo           #+#    #+#             */
/*   Updated: 2016/12/02 19:26:46 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	dimensions(t_tetriminos *v, int i, int j)
{
	v->l = 0;
	v->h = 0;
	while (v->tetri[++i][0])
	{
		j = -1;
		while (v->tetri[i][++j])
		{
			if (v->tetri[i][j] >= 'A' && v->tetri[i][j] <= 'Z')
				(v->h)++;
			if (v->tetri[i][j] >= 'A' && v->tetri[i][j] <= 'Z')
				break ;
		}
	}
	j = -1;
	while (v->tetri[0][++j])
	{
		i = -1;
		while (v->tetri[++i][j])
		{
			if (v->tetri[i][j] >= 'A' && v->tetri[i][j] <= 'Z')
				(v->l)++;
			if (v->tetri[i][j] >= 'A' && v->tetri[i][j] <= 'Z')
				break ;
		}
	}
}
