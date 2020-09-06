/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		solvedestroyer(t_result *solve)
{
	free(solve->pathes);
	free(solve->antsforpath);
	free(solve);
}

void		solvesaver(t_result *solve)
{
	t_rooms	*room;
	int		x;

	x = 0;
	while (x < solve->count)
	{
		room = solve->pathes[x].origin;
		while (room->succ != NULL)
		{
			room->bests = room->succ;
			room = room->succ;
		}
		x++;
	}
}

void		presolve(t_base *lm)
{
	if (lm->ants == 0)
	{
		if (lm->movesf)
			ft_putstr("\n");
	}
	else if (linkexclusive(lm->map.start, lm->map.finish) != NULL)
	{
		if (lm->movesf)
			printmovesnormal(lm);
	}
	else
		solvehard(lm);
}
