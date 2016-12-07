/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:55:41 by becorbel          #+#    #+#             */
/*   Updated: 2016/12/02 17:55:42 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**small(int i, int j, char **tetrim, t_tetriminos *t)
{
	int k;
	int l;

	k = 0;
	while (tetrim[k][j] == '.' && k < 3)
		k++;
	l = 0;
	while (tetrim[i][l] == '.' && l < 4)
		l++;
	if (tetrim[k][j] == '.' && l < 4)
		return (small(i, j + 1, tetrim, t));
	else if (l == 4 && tetrim[k][j] != '.')
		return (small(i + 1, j, tetrim, t));
	else if (tetrim[k][j] == '.' && l == 4)
		return (small(i + 1, j + 1, tetrim, t));
	return (replace(i, j, tetrim, t));
}
