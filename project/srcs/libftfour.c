/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftfour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:31:09 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordsc(const char *s, char c)
{
	size_t words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && (*s != c))
				s++;
		}
	}
	return (words);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	count;

	count = 0;
	if (!s || start + len > ft_strlen(s))
		return (NULL);
	if ((res = ft_strnew(len)))
	{
		while (len)
		{
			res[count] = s[start];
			count++;
			start++;
			len--;
		}
		res[count] = '\0';
	}
	return (res);
}
