/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findshortest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	linkdistance(t_rooms *first, t_stack *stack)
{
	int		distance;
	t_list	*list;
	t_links	*links;
	t_rooms	*second;

	list = first->links;
	while (list != NULL)
	{
		links = list->data;
		second = links->dst;
		distance = first->distance + links->weight;
		if (distance < second->distance)
		{
			second->distance = distance;
			second->parent = first;
			stackpusher(stack, second);
		}
		list = list->next;
	}
}

int		findshortest(t_rooms *first, t_rooms *second)
{
	t_stack	*stack;

	stack = createstack();
	first->distance = 0;
	while (first != NULL && first != second)
	{
		linkdistance(first, stack);
		first = stackpoper(stack);
	}
	stackdestroyer(stack);
	if (first == second)
		return (1);
	return (0);
}
