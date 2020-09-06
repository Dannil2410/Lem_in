/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		sortpathes(t_pathes *all, int pathes)
{
	t_pathes	temp;
	int			x;
	int			y;

	x = 0;
	while (x < pathes - 1)
	{
		y = x + 1;
		while (y < pathes)
		{
			if (all[x].length > all[y].length)
			{
				temp = all[x];
				all[x] = all[y];
				all[y] = temp;
			}
			y++;
		}
		x++;
	}
}

int			findlength(t_rooms *destination)
{
	int	length;

	length = 0;
	while (destination != NULL)
	{
		length++;
		destination = destination->succ;
	}
	return (length);
}

t_pathes	*initializepath(t_rooms *start, int pathes)
{
	int			i;
	t_pathes	*all;
	t_list		*list;
	t_links		*links;

	if (!(all = malloc(pathes * sizeof(t_pathes))))
		helpuse(3);
	list = start->links;
	i = 0;
	while (i < pathes)
	{
		links = list->data;
		if (links->dst->pred != NULL)
		{
			all[i].origin = links->dst;
			all[i].length = findlength(links->dst);
			i++;
		}
		list = list->next;
	}
	return (all);
}
