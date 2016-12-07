/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:54:00 by becorbel          #+#    #+#             */
/*   Updated: 2016/12/07 20:35:20 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	fillit(char *av, int ret, int sq)
{
	t_tetriminos	*t;
	t_struct		v;
	char			**grid;
	int				fd;
	char			buf[547];

	grid = create_tab(105, 105, 0, NULL);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	ret = read(fd, buf, 546);
	buf[ret] = '\0';
	if (all_check(buf) == 0)
		return (0);
	ft_strsplit(buf, '\n');
	v.n_tetri = split_count(buf, &v, 0);
	while (sq * sq < ((v.n_tetri + 1) * 4))
		sq++;
	t = tetri_list(0, v.tab, v.n_tetri);
	one(sq, &v, t, grid);
	if (close(fd) == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr("Usage : ./fillit\n");
	fillit(argv[1], 0, 2);
	return (0);
}
