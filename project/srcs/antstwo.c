/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antstwo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			antsmover(t_rooms **temp, t_result *best)
{
	int	x;

	x = 0;
	while (x < best->count && best->antsforpath[x] > 0)
	{
		best->antsforpath[x]--;
		temp[x] = best->pathes[x].origin;
		x++;
	}
	return (x);
}

void		antsmovement(t_rooms **temp, int max)
{
	int	x;

	x = 0;
	while (x < max)
	{
		if (temp[x] != NULL)
			temp[x] = temp[x]->bests;
		x++;
	}
}
