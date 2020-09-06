/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtwo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	readlinks(t_base *lm, t_data *data)
{
	int	flag;

	flag = 1;
	if (data->type != 6 && data->type != 9)
		helpuse(13);
	while (flag)
	{
		if (data->type == 6)
		{
			if (ft_strcmp(data->value.link.src, data->value.link.dst) == 0)
				helpuse(14);
			addlink(lm, data);
		}
		if (data->type == 6)
			flag = 1;
		else
			flag = 0;
		if (flag)
			readdata(lm, data);
	}
}

void	readrooms(t_base *lm, t_data *data)
{
	int	flag;

	flag = 1;
	while (flag)
	{
		if (data->type == 4)
			addroom(lm, data);
		else if (data->type == 1 || data->type == 2)
			addstartendr(lm, data);
		if (data->type == 4)
			flag = 1;
		else
			flag = 0;
		if (flag)
			readdata(lm, data);
	}
}

void	readants(t_base *lm, t_data *data)
{
	if (data->type == 9)
		helpuse(6);
	if (data->type != 8)
		helpuse(7);
	lm->ants = data->value.ants;
	readdata(lm, data);
}
