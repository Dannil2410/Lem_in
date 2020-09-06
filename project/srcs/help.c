/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	helpusetwo(int flag)
{
	flag == 1 ? ft_putstr_fd("Usage: ./lem-in < filename\n", 2) : 0;
	flag == 3 ? ft_putstr_fd("Error in malloc\n", 2) : 0;
	flag == 4 ? ft_putstr_fd("File is too large\n", 2) : 0;
	flag == 5 ? ft_putstr_fd("Error in get_next_line\n", 2) : 0;
	flag == 6 ? ft_putstr_fd("Number of ants is not set\n", 2) : 0;
	flag == 7 ? ft_putstr_fd("Invalid number of ants\n", 2) : 0;
	flag == 8 ? ft_putstr_fd("A room with the same name already exists\n",
		2) : 0;
	flag == 9 ? ft_putstr_fd("The start has already been indicated\n", 2) : 0;
	flag == 10 ? ft_putstr_fd("The end has already been indicated\n", 2) : 0;
	flag == 11 ? ft_putstr_fd("Room is missing\n", 2) : 0;
	flag == 12 ? ft_putstr_fd("Invalid room format\n", 2) : 0;
	flag == 13 ? ft_putstr_fd("Invalid input format\n", 2) : 0;
	flag == 14 ? ft_putstr_fd("The link cannot be in itself\n", 2) : 0;
	flag == 15 ? ft_putstr_fd("Sender does not exist\n", 2) : 0;
	flag == 16 ? ft_putstr_fd("Recipient does not exist\n", 2) : 0;
	flag == 17 ? ft_putstr_fd("This link already exists\n", 2) : 0;
	flag == 18 ? ft_putstr_fd("Invalid link format\n", 2) : 0;
	flag == 19 ? ft_putstr_fd("Start room is missing\n", 2) : 0;
	flag == 20 ? ft_putstr_fd("End room is missing\n", 2) : 0;
	flag == 21 ? ft_putstr_fd("Number of ants is too big\n", 2) : 0;
	flag == 22 ? ft_putstr_fd("No solutions\n", 2) : 0;
	flag == 23 ? ft_putstr_fd("A room with the same coords already exists\n",
		2) : 0;
	exit(1);
}

void	helpuse(int flag)
{
	if (flag == 2)
	{
		ft_putstr("Project goal:\n");
		ft_putstr("Find the quickest way to get n ants across the farm\n");
		ft_putstr("Map example:\n");
		ft_putstr("3\n##start\n0 1 0\n##end\n");
		ft_putstr("1 5 0\n2 9 0\n3 13 0\n0-2\n2-3\n3-1\n");
		ft_putstr("Usage: ./lem-in < filename\n");
	}
	else
		helpusetwo(flag);
}

void	helptimetwo(t_base *lm, char **av)
{
	char	*str;

	while ((str = *(++av)))
	{
		if (str[0] == '-')
		{
			lm->needf = (ft_strcmp(str, "--help") == 0) ? 1 : 0;
			if (lm->needf == 0 && lm->inputf == 0 && lm->movesf == 0)
				helpuse(1);
		}
	}
}

void	helptime(t_base *lm, int ac, char **av)
{
	lm->needf = 0;
	if (ac > 1)
	{
		lm->inputf = 0;
		lm->movesf = 0;
		helptimetwo(lm, av);
	}
	else
	{
		lm->inputf = 1;
		lm->movesf = 1;
	}
}
