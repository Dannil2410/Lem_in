/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	checklink(t_data *data, char *line)
{
	size_t		i;
	char const	*destination;

	i = 0;
	while (line[i] != '-')
		i++;
	destination = line + i + 1;
	if (i > 0 && *destination && !ft_strchr(destination, '-'))
	{
		data->type = 6;
		data->value.link.src = ft_strsub(line, 0, i);
		data->value.link.dst = ft_strdup(destination);
	}
	else
		data->type = 5;
}

void	checkroom(t_data *data, char *line)
{
	char	**input;

	input = ft_strsplit(line, ' ');
	if (input[0] && input[1] && input[2] && !input[3]
		&& !ft_strchr(input[0], '-')
			&& checknumber(input[1], &data->value.room.x)
				&& checknumber(input[2], &data->value.room.y))
	{
		data->type = 4;
		data->value.room.name = input[0];
		free(input[1]);
		free(input[2]);
		free(input);
	}
	else
	{
		data->type = 5;
		freedarray(input);
	}
}

void	checkas(t_data *data, char *line, int flag)
{
	int number;

	number = 0;
	if (flag == 0)
	{
		data->type = 5;
		if (checknumber(line, &number) && number >= 0)
		{
			data->type = 8;
			data->value.ants = number;
		}
	}
	if (flag == 1)
	{
		data->type = 3;
		if (ft_strcmp(line, "##start") == 0)
			data->type = 1;
		else if (ft_strcmp(line, "##end") == 0)
			data->type = 2;
	}
}
