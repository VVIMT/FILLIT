/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:55:08 by becorbel          #+#    #+#             */
/*   Updated: 2016/12/07 20:35:41 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct			s_struct
{
	int					n_tetri;
	int					k;
	int					x;
	long				i;
	long				j;
	long				sq;
	char				**tab;
	char				**grid;
}						t_struct;

typedef struct			s_tetriminos
{
	char				**tetri;
	int					l;
	int					h;
	int					i;
	int					j;
	int					coorx0;
	int					coory0;
	int					coorx1;
	int					coory1;
	int					coorx2;
	int					coory2;
	int					coorx3;
	int					coory3;
	long				tetri_pos;
	long				limit;
	struct s_tetriminos	*next;
}						t_tetriminos;

int						one(long sq, t_struct *v, t_tetriminos *t, char **grid);
void					dimensions(t_tetriminos *v, int i, int j);
void					reset(char **grid, long carre);
void					square_limit(char **grid, char c, long sq);
int						compare(t_tetriminos *lst, int i, int j);
int						fillit(char *av, int ret, int sq);
int						main(int argc, char **argv);
int						split_count(char *tab, t_struct *v, long k);
int						check(long sq, long pos, t_tetriminos *t, char **grid);
void					stack(t_tetriminos *t, char **grid);
void					rm(long sq, long pos, t_tetriminos *t, char **grid);
char					**create_tab(long i, long j, long counter, char **data);
char					**replace(int i, int j, char **tetrim, t_tetriminos *t);
void					coor(int count, int x, int y, t_tetriminos *t);
char					**small(int i, int j, char **tetrim, t_tetriminos *t);
t_tetriminos			*tetri_list(int i, char **tab, int n_tetri);
long					ft_print(char **data);
int						all_check(char *s);

#endif
