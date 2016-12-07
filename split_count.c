/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:56:00 by becorbel          #+#    #+#             */
/*   Updated: 2016/12/02 17:56:00 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	split_count(char *tab, t_struct *v, long k)
{
	char **tab2d;

	tab2d = create_tab(27, 22, 0, NULL);
	while (tab[k])
	{
		if (tab[k] == '\n' && tab[k + 1] == '\n')
		{
			tab2d[v->i][v->j] = tab[k];
			(v->j)++;
			tab2d[v->i][v->j] = '\0';
			(v->i)++;
			v->j = 0;
			k = k + 2;
		}
		if (tab[k] == '#')
			tab2d[v->i][v->j] = 'A' + v->i;
		else
			tab2d[v->i][v->j] = tab[k];
		(v->j)++;
		k++;
	}
	tab2d[v->i][v->j] = '\0';
	v->tab = tab2d;
	return (v->i);
}
