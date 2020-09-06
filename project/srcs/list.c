/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	*poper(t_list **head)
{
	t_list	*element;
	void	*data;

	element = *head;
	*head = element->next;
	data = element->data;
	free(element);
	return (data);
}

void	pusher(t_list **head, void *data)
{
	t_list	*element;

	if (!(element = malloc(sizeof(t_list))))
		helpuse(3);
	element->data = data;
	element->next = *head;
	*head = element;
}
