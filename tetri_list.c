/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:27:05 by vinvimo           #+#    #+#             */
/*   Updated: 2016/12/05 19:36:06 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetriminos	*tetri_list(int i, char **tab, int n_tetri)
{
	t_tetriminos	*list;
	t_tetriminos	*tmp;

	if (!(list = (t_tetriminos*)malloc(sizeof(t_tetriminos))))
		return (NULL);
	tmp = list;
	list->next = NULL;
	while (i <= n_tetri)
	{
		tmp->tetri_pos = 0;
		tmp->tetri = small(0, 0, ft_strsplit(tab[i++], '\n'), tmp);
		dimensions(tmp, -1, -1);
		if (i > n_tetri)
			tmp->next = NULL;
		else
		{
			if (!(tmp->next = (t_tetriminos*)malloc(sizeof(t_tetriminos))))
				return (NULL);
			tmp = tmp->next;
		}
	}
	return (list);
}
