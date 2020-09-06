/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antsone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		additionsplit(t_result *solve, int antsleft)
{
	int	i;

	solve->turns++;
	i = 0;
	while (antsleft--)
	{
		solve->antsforpath[i]++;
		i++;
	}
}

void		antsdistribute(t_result *solve, int i)
{
	int	x;

	x = 0;
	while (x < i)
	{
		solve->antsforpath[x] = solve->turns - solve->pathes[x].length + 1;
		x++;
	}
	while (x < solve->count)
	{
		solve->antsforpath[x] = 0;
		x++;
	}
}

int			equalsplit(t_result *solve, int pathes)
{
	int	i;
	int	temp;

	i = 1;
	while (i < solve->count)
	{
		temp = solve->pathes[i].length - solve->pathes[i - 1].length;
		if (pathes / i <= temp)
			break ;
		pathes -= temp * i;
		i++;
	}
	temp = pathes / i;
	pathes -= temp * i;
	solve->turns = solve->pathes[i - 1].length + temp - 1;
	if (solve->turns < 0)
		helpuse(21);
	antsdistribute(solve, i);
	return (pathes);
}

void		goants(t_result *solve, int pathes)
{
	int	antsleft;

	antsleft = equalsplit(solve, pathes);
	if (antsleft > 0)
		additionsplit(solve, antsleft);
}
