/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	modifpath(t_rooms *first, t_rooms *temp, t_rooms *second)
{
	t_rooms	*new;

	linkdeleter(second, temp);
	while (temp != first)
	{
		linkdeleter(temp, temp->succ);
		linkdeleter(temp, temp->pred);
		new = createroom();
		new->links = temp->links;
		temp->links = NULL;
		linkpusher(temp->succ, new, -1);
		linkpusher(new, temp, 0);
		if (temp->pred == first)
		{
			linkdeleter(first, temp);
			linkpusher(temp, first, -1);
		}
		temp = temp->pred;
	}
}

void	modifmap(t_rooms *first, t_rooms *second)
{
	t_list	*list;
	t_links	*links;

	list = second->links;
	while (list != NULL)
	{
		links = list->data;
		list = list->next;
		if (links->dst->succ == second)
			modifpath(first, links->dst, second);
	}
}
