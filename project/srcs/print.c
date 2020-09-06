/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	printmovesnormal(t_base *lm)
{
	int			i;
	int			flag;

	ft_putchar('\n');
	i = 0;
	flag = 1;
	while (i < lm->ants)
	{
		if (!flag)
			ft_putchar(' ');
		else
			flag = 0;
		ft_putchar('L');
		ft_putnbr(i + 1);
		ft_putchar('-');
		ft_putstr(lm->map.finish->name);
		i++;
	}
	ft_putchar('\n');
}

void	printresult(t_rooms **temp, int max)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (i < max)
	{
		if (temp[i] != NULL)
		{
			if (!flag)
				ft_putchar(' ');
			else
				flag = 0;
			ft_putchar('L');
			ft_putnbr(i + 1);
			ft_putchar('-');
			ft_putstr(temp[i]->name);
		}
		i++;
	}
	if (!flag)
		ft_putchar('\n');
}

void	printmoveshard(t_result *best, int ants)
{
	t_rooms	**temp;
	int		count;
	int		max;

	if (!(temp = malloc(ants * sizeof(t_rooms *))))
		helpuse(3);
	max = 0;
	count = best->turns;
	ft_putchar('\n');
	while (count--)
	{
		antsmovement(temp, max);
		max += antsmover(temp + max, best);
		printresult(temp, max);
	}
	free(temp);
}

void	printinput(t_input *input)
{
	t_list	*lines;

	lines = input->lines;
	while (lines != NULL)
	{
		ft_putstr(lines->data);
		ft_putchar('\n');
		lines = lines->next;
	}
}
