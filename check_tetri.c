/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:54:36 by becorbel          #+#    #+#             */
/*   Updated: 2016/12/02 17:54:39 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_split_fct(char *s, int *i, int *j)
{
	while (s[*i] != '\n')
	{
		if (s[*i] != '.' && s[*i] != '#')
			return (0);
		(*i)++;
		(*j)++;
	}
	return (1);
}

int	check_str(char *s, int i)
{
	int	j;
	int	n;

	n = 0;
	while (s[i])
	{
		j = 0;
		if (!(ft_split_fct(s, &i, &j)))
			return (0);
		n++;
		if (j != 4)
			return (0);
		if (n == 4)
		{
			if (s[i + 1] != '\n' && s[i + 1] != '\0')
				return (0);
			if (s[i + 1] == '\n')
				if ((check_str(s, i + 2)) == 1)
					return (1);
			if (s[i + 1] == '\0')
				return (1);
		}
		i++;
	}
	return (1);
}

int	check_tetri(char *s, int i, int j)
{
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (j++ > 0)
			{
				if (s[i - 5] != '#' && s[i - 1] != '#')
				{
					if (s[i - 4] != '#' && s[i - 3] != '#' && s[i - 2] != '#')
						return (0);
					if (s[i + 1] == '#')
						return (check_tetri(s, i + 1, j));
					return (0);
				}
				else
					return (check_tetri(s, i + 1, j));
			}
			else if (s[i + 1] != '#' && s[i + 5] != '#')
				return (0);
		}
		if (s[i] == '\n' && s[i + 1] == '\n')
			j = 0;
		i++;
	}
	return (1);
}

int	check_nb_piece(char *s, int i)
{
	int	j;

	j = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			j++;
			if (j > 4)
				return (0);
		}
		if (s[i] == '\n' && s[i + 1] == '\n')
		{
			if (j == 4)
			{
				if (check_nb_piece(s, i + 2) == 0)
					return (0);
				return (1);
			}
		}
		i++;
	}
	if (j == 4)
		return (1);
	return (0);
}

int	all_check(char *s)
{
	int i;

	i = 0;
	if (!(check_str(s, i)))
	{
		ft_putendl("error");
		return (0);
	}
	if (!(check_nb_piece(s, i)))
	{
		ft_putendl("error");
		return (0);
	}
	if (!(check_tetri(s, i, 0)))
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}
