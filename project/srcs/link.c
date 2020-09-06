/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_rooms	*linkpoper(t_rooms *first)
{
	t_rooms	*second;

	second = ((t_links *)first->links->data)->dst;
	free(poper(&first->links));
	return (second);
}

void	linkdeleter(t_rooms *first, t_rooms *second)
{
	t_list	**list;

	list = &first->links;
	while (((t_links *)(*list)->data)->dst != second)
		list = &(*list)->next;
	free(poper(list));
}

void	linkpusher(t_rooms *first, t_rooms *second, int weight)
{
	t_links	*link;

	if (!(link = malloc(sizeof(t_links))))
		helpuse(3);
	link->dst = second;
	link->weight = weight;
	pusher(&first->links, link);
}

t_links	*linkexclusive(t_rooms *first, t_rooms *second)
{
	t_list	*links;

	links = first->links;
	while (links != NULL)
	{
		if (((t_links *)links->data)->dst == second)
			return (links->data);
		links = links->next;
	}
	return (NULL);
}

void	addlink(t_base *lm, t_data *data)
{
	t_rooms	*first;
	t_rooms *second;

	if ((first = roomexclusive(lm->map.rooms, data->value.link.src)) == NULL)
		helpuse(15);
	if ((second = roomexclusive(lm->map.rooms, data->value.link.dst)) == NULL)
		helpuse(16);
	if (linkexclusive(first, second) != NULL)
		helpuse(17);
	linkpusher(first, second, 1);
	linkpusher(second, first, 1);
	free(data->value.link.src);
	free(data->value.link.dst);
}
