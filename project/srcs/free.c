/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	freedates(t_list **list)
{
	t_list *next;

	while (*list)
	{
		next = *list;
		*list = (*list)->next;
		free(next->data);
		free(next);
	}
}

void	freeroomname(t_list *list)
{
	t_rooms	*next;

	while (list)
	{
		next = (t_rooms *)list->data;
		free(next->name);
		list = list->next;
	}
}

void	freelinks(t_list *list)
{
	t_rooms	*next;
	t_list	*links;

	links = NULL;
	while (list)
	{
		next = (t_rooms *)list->data;
		links = (t_list *)next->links;
		freedates(&links);
		list = list->next;
	}
}

void	freebase(t_base *base)
{
	freedates(&base->input.lines);
	freeroomname(base->map.rooms);
	freelinks(base->map.rooms);
	freedates(&base->map.rooms);
}
