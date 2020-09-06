/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		coordexclusive(t_list *rooms, int x, int y)
{
	t_rooms	*room;

	while (rooms != NULL)
	{
		room = rooms->data;
		if (x == room->x && y == room->y)
			return (0);
		rooms = rooms->next;
	}
	return (1);
}

void	addstartendr(t_base *lm, t_data *data)
{
	int	flag;

	flag = data->type == 1 ? 1 : 0;
	if (flag && lm->map.start != NULL)
		helpuse(9);
	if (!flag && lm->map.finish != NULL)
		helpuse(10);
	readdata(lm, data);
	if (data->type == 9)
		helpuse(11);
	if (data->type != 4)
		helpuse(12);
	addroom(lm, data);
	if (flag)
		lm->map.start = lm->map.rooms->data;
	else
		lm->map.finish = lm->map.rooms->data;
}

t_rooms	*createroom(void)
{
	t_rooms	*room;

	if (!(room = malloc(sizeof(t_rooms))))
		helpuse(3);
	room->links = NULL;
	room->distance = 2147483647;
	room->parent = NULL;
	room->pred = NULL;
	room->succ = NULL;
	room->bests = NULL;
	return (room);
}

t_rooms	*roomexclusive(t_list *rooms, char *name)
{
	t_rooms	*room;

	while (rooms != NULL)
	{
		room = rooms->data;
		if (ft_strcmp(room->name, name) == 0)
			return (room);
		rooms = rooms->next;
	}
	return (NULL);
}

void	addroom(t_base *lm, t_data *data)
{
	t_rooms	*room;

	if (roomexclusive(lm->map.rooms, data->value.room.name) != NULL)
		helpuse(8);
	if (!(coordexclusive(lm->map.rooms, data->value.room.x,
		data->value.room.y)))
		helpuse(23);
	room = createroom();
	room->name = data->value.room.name;
	room->x = data->value.room.x;
	room->y = data->value.room.y;
	pusher(&lm->map.rooms, room);
}
