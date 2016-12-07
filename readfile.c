/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:47:19 by becorbel          #+#    #+#             */
/*   Updated: 2016/11/28 18:49:08 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	read_file(char *buff, char *s)
{
	int	r;
	int	f;

	if (!(f = open(s, O_RDONLY)))
		return (0);
	while ((r = read(f, buff, BUFF_SIZE)))
		buff[r] = '\0';
	return (1);
}
