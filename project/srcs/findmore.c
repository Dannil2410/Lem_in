/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findmore.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	cleanrooms(t_list *rooms)
{
	t_rooms	*element;

	while (rooms != NULL)
	{
		element = rooms->data;
		element->distance = 2147483647;
		element->parent = NULL;
		rooms = rooms->next;
	}
}

void	findcycle(t_rooms *first, t_rooms *second)
{
	t_rooms	*one;
	t_rooms	*two;

	two = second;
	while ((one = two->parent) != NULL)
	{
		if (one->pred != two && two->succ != one)
		{
			if (one != first)
				one->succ = two;
			if (two != second)
				two->pred = one;
		}
		else
		{
			if (one->pred == two)
				one->pred = NULL;
			if (two->succ == one)
				two->succ = NULL;
		}
		two = one;
	}
}

void	checkparents(t_rooms *room)
{
	t_rooms	*parent;
	t_rooms	*temp;
	t_links	*links;

	while ((parent = room->parent) != NULL)
	{
		links = parent->links->data;
		if (links->weight == 0)
		{
			temp = links->dst;
			if (temp != room)
				room->parent = temp;
			temp->parent = parent->parent;
		}
		room = room->parent;
	}
}

int		findmore(t_map *map)
{
	int	flag;

	flag = 0;
	modifmap(map->start, map->finish);
	flag = findshortest(map->start, map->finish);
	checkparents(map->finish);
	restoremap(map->start, map->finish);
	findcycle(map->start, map->finish);
	cleanrooms(map->rooms);
	return (flag);
}
