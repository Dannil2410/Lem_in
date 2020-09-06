/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	restorepath(t_rooms *first, t_rooms *temp, t_rooms *second)
{
	t_rooms	*now;
	t_rooms	*before;

	linkdeleter(second, temp);
	while (temp != first)
	{
		now = linkpoper(temp);
		before = linkpoper(now);
		now->links = temp->links;
		free(temp);
		linkpusher(now, now->succ, 1);
		linkpusher(now->succ, now, 1);
		temp = before;
	}
	linkpusher(first, now, 1);
	linkpusher(now, first, 1);
}

void	restoremap(t_rooms *first, t_rooms *second)
{
	t_list	*list;
	t_links	*links;

	list = second->links;
	while (list != NULL)
	{
		links = list->data;
		list = list->next;
		if (links->weight == -1)
			restorepath(first, links->dst, second);
	}
}
