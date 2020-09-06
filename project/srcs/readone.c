/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	adddata(t_data *data, char *line)
{
	if (line[0] == '#')
		checkas(data, line, 1);
	else if (ft_strchr(line, ' ') && line[0] != ' ')
		checkroom(data, line);
	else if (ft_strchr(line, '-'))
		checklink(data, line);
	else if (line[0] == '\0')
		data->type = 7;
	else
		checkas(data, line, 0);
}

void	addline(t_base *lm, char *line)
{
	if (lm->input.lines == NULL)
	{
		pusher(&lm->input.lines, line);
		lm->input.last = lm->input.lines;
	}
	else
	{
		pusher(&lm->input.last->next, line);
		lm->input.last = lm->input.last->next;
	}
	lm->input.countl++;
	if (lm->input.countl < 0)
		helpuse(4);
}

void	readdata(t_base *lm, t_data *data)
{
	int		flag;
	char	*line;

	while ((flag = get_next_line(0, &line)) == 1)
	{
		addline(lm, line);
		adddata(data, line);
		if (data->type != 3)
			return ;
	}
	if (flag == 0)
	{
		data->type = 9;
		return ;
	}
	if (flag == -1)
		helpuse(5);
}

void	initializelm(t_base *lm)
{
	lm->map.rooms = NULL;
	lm->map.start = NULL;
	lm->map.finish = NULL;
	lm->input.countl = 0;
	lm->input.lines = NULL;
	lm->input.last = NULL;
}

void	reader(t_base *lm)
{
	t_data	data;

	initializelm(lm);
	readdata(lm, &data);
	readants(lm, &data);
	readrooms(lm, &data);
	readlinks(lm, &data);
	if (data.type != 9)
		helpuse(18);
	if (lm->map.start == NULL)
		helpuse(19);
	if (lm->map.finish == NULL)
		helpuse(20);
}
