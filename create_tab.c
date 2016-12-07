/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:54:55 by becorbel          #+#    #+#             */
/*   Updated: 2016/12/02 17:54:56 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_tab(long i, long j, long counter, char **data)
{
	if (!(data = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	while (counter <= i)
	{
		data[counter] = (char*)malloc(sizeof(char) * (j + 1));
		if (!(data[counter]))
			return (NULL);
		counter++;
	}
	reset(data, i);
	return (data);
}
