/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	freedarray(char **input)
{
	char	**temp;

	temp = input;
	while (*temp)
		free(*(temp++));
	free(input);
}

int		isinteger(char *str)
{
	int	length;
	int	temp;
	int	flag;

	length = 0;
	temp = 0;
	flag = 0;
	while (str[length])
		length++;
	flag = str[0] == '-' ? 1 : 0;
	if (length > 10)
		return (0);
	else if (length == 10)
	{
		temp = flag == 1 ? str[1] - '0' : str[0] - '0';
		length = flag == 1 ? 2 : 1;
		while (str[length])
		{
			temp = 10 * temp + str[length] - '0';
			length++;
			if (temp <= 0)
				return (0);
		}
	}
	return (1);
}

int		checknumber(char *str, int *coordinates)
{
	int	sign;
	int	abs;

	if (!(isinteger(str)))
		return (0);
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	abs = 0;
	while ('0' <= *str && '9' >= *str)
	{
		abs = abs * 10 + (int)(*(str++) - '0');
		if (abs < 0 && !(abs == -2147483648 && *str == '\0'))
			return (0);
	}
	if (*str)
		return (0);
	*coordinates = sign * abs;
	return (1);
}
