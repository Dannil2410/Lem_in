/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t check;

	check = 0;
	while (s1[check] == s2[check])
	{
		check++;
		if (s1[check] == '\0' && s2[check] == '\0')
			return (0);
	}
	return ((unsigned char)s1[check] - (unsigned char)s2[check]);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (0);
}

void	*ft_memalloc(size_t size)
{
	void *mm;

	if (!(mm = malloc(size)))
		return (NULL);
	ft_bzero(mm, size);
	return (mm);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char *)s;
	while (n)
	{
		*temp++ = '\0';
		n--;
	}
}

int		ft_atoi(const char *str)
{
	long int	result;
	int			i;
	int			sign;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
	{
		if (sign == 1 && (result > 922337203685477580
					|| (result == 922337203685477580 && str[i] + '0' >= 7)))
			return (-1);
		if (sign == -1 && (result < -922337203685477580
					|| (result == -922337203685477580 && str[i] + '0' >= '8')))
			return (0);
		result = result * 10 + str[i++] - '0';
	}
	return (sign * result);
}
