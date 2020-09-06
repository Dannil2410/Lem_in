/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	stackdestroyer(t_stack *stack)
{
	while (stack->elements != NULL)
		(void)poper(&stack->elements);
	free(stack);
}

t_rooms	*stackpoper(t_stack *stack)
{
	t_list	**list;
	t_list	**listmin;
	int		distance;

	if (stack->elements == NULL)
		return (NULL);
	list = &stack->elements;
	listmin = list;
	distance = ((t_rooms *)(*list)->data)->distance;
	while (*list != NULL)
	{
		if (((t_rooms *)(*list)->data)->distance < distance)
		{
			listmin = list;
			distance = ((t_rooms *)(*list)->data)->distance;
		}
		list = &(*list)->next;
	}
	return (poper(listmin));
}

void	stackpusher(t_stack *stack, t_rooms *room)
{
	t_list	*element;

	element = stack->elements;
	while (element != NULL)
	{
		if (element->data == room)
			return ;
		element = element->next;
	}
	pusher(&stack->elements, room);
}

t_stack	*createstack(void)
{
	t_stack	*stack;

	if (!(stack = malloc(sizeof(t_stack))))
		helpuse(3);
	stack->elements = NULL;
	return (stack);
}
