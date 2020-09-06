/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfttwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	count;
	char	*result;

	if (size > size + 1)
		return (NULL);
	if (!(result = ft_memalloc(size + 1)))
		return (NULL);
	count = 0;
	while (count < size)
	{
		result[count] = '\0';
		count++;
	}
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	length;
	int		x;
	int		y;

	length = 0;
	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	x = 0;
	while (s1[x])
	{
		res[x] = s1[x];
		x++;
	}
	y = 0;
	while (s2[y])
	{
		res[x + y] = s2[y];
		y++;
	}
	res[x + y] = '\0';
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		length;
	int		check;

	length = 0;
	while (s1[length])
		length++;
	if (!(copy = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	check = 0;
	while (s1[check])
	{
		copy[check] = s1[check];
		check++;
	}
	copy[check] = '\0';
	return (copy);
}

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
