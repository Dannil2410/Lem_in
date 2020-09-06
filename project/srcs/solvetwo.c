/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvetwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_result	*createsolve(t_rooms *start, int ants, int pathes)
{
	t_result	*solve;

	if (!(solve = malloc(sizeof(t_result))))
		helpuse(3);
	solve->count = pathes;
	solve->pathes = initializepath(start, pathes);
	sortpathes(solve->pathes, pathes);
	if (!(solve->antsforpath = malloc(pathes * sizeof(int))))
		helpuse(3);
	goants(solve, ants);
	return (solve);
}

void		solver(t_result **best, t_rooms *start, int ants, int pathes)
{
	t_result	*solve;

	solve = createsolve(start, ants, pathes);
	if (*best == NULL || solve->turns < (*best)->turns)
	{
		solvesaver(solve);
		if (*best != NULL)
			solvedestroyer(*best);
		*best = solve;
	}
	else
		solvedestroyer(solve);
}

int			countlinks(t_rooms *src)
{
	int		count;
	t_list	*links;

	count = 0;
	links = src->links;
	while (links != NULL)
	{
		count++;
		links = links->next;
	}
	return (count);
}

int			countmax(t_base *lm)
{
	int	max;
	int	i;

	max = lm->ants;
	if ((i = countlinks(lm->map.start)) < max)
		max = i;
	if ((i = countlinks(lm->map.finish)) < max)
		max = i;
	return (max);
}

void		solvehard(t_base *lm)
{
	int			max;
	int			pathes;
	t_result	*best;

	max = countmax(lm);
	pathes = 0;
	best = NULL;
	while (pathes < max && findmore(&lm->map))
	{
		pathes++;
		solver(&best, lm->map.start, lm->ants, pathes);
	}
	if (pathes == 0)
		helpuse(22);
	if (lm->movesf)
		printmoveshard(best, lm->ants);
	solvedestroyer(best);
}
