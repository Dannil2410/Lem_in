/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:44:42 by sazalee           #+#    #+#             */
/*   Updated: 2019/06/25 14:32:27 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			gnl_res(int res, char **line, char *mem)
{
	if (res != 0 || mem == NULL || mem[0] == '\0')
	{
		if (!res && *line)
			*line = NULL;
		return (1);
	}
	return (0);
}

int			gnl_check(char **mem, char **line)
{
	char	*temp;
	char	*tempchr;
	int		counter;

	counter = 0;
	tempchr = *mem;
	while (tempchr[counter] != '\n')
	{
		if (!tempchr[counter])
			return (0);
		counter++;
	}
	temp = &tempchr[counter];
	*temp = '\0';
	*line = ft_strdup(*mem);
	*mem = ft_strdup(temp + 1);
	free(tempchr);
	return (1);
}

int			gnl_read(int fd, char *copy, char **mem, char **line)
{
	int		res;
	char	*temp;

	while ((res = read(fd, copy, BUFF_SIZE)) > 0)
	{
		copy[res] = '\0';
		if (*mem)
		{
			temp = *mem;
			*mem = ft_strjoin(temp, copy);
			free(temp);
			temp = NULL;
		}
		else
			*mem = ft_strdup(copy);
		if (gnl_check(mem, line))
		{
			res = (res > 0) ? 1 : res;
			return (res);
		}
	}
	if (res > 0)
		return (1);
	else
		return (res);
}

int			get_next_line(const int fd, char **line)
{
	static char	*mem[10241];
	char		*copy;
	int			res;
	int			counter;

	if (!line || fd < 0 || fd >= 10241 || (read(fd, mem[fd], 0) < 0)
			|| !(copy = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (mem[fd])
		if (gnl_check(&mem[fd], line))
		{
			free(copy);
			return (1);
		}
	counter = 0;
	while (counter < BUFF_SIZE)
		copy[counter++] = '\0';
	res = gnl_read(fd, copy, &mem[fd], line);
	free(copy);
	if (gnl_res(res, line, mem[fd]))
		return (res);
	*line = mem[fd];
	mem[fd] = NULL;
	return (1);
}
