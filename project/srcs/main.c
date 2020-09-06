/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int ac, char **av)
{
	t_base	lm;

	helptime(&lm, ac, av);
	if (lm.needf == 1)
	{
		helpuse(2);
		return (0);
	}
	reader(&lm);
	if (lm.inputf)
		printinput(&lm.input);
	presolve(&lm);
	freebase(&lm);
	return (0);
}
