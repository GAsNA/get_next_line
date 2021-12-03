/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:02:13 by rleseur           #+#    #+#             */
/*   Updated: 2021/12/03 09:08:24 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*tmp;
	char		*str;
	int			index;
	int			size;

	if (fd == -1)
		return (0);
	if (!mem)
		mem = ft_strdup("");
	str = ft_strdup(mem);
	index = BUFFER_SIZE;
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (0);
	size = 0;
	while (index == BUFFER_SIZE)
	{
		size = read(fd, tmp, BUFFER_SIZE);
		tmp[BUFFER_SIZE] = '\0';
		index = get_index_backslash_n(tmp);
		str = ft_strjoin(str, tmp, index);
		mem = ft_strdup(&tmp[index]);
	}
	if (size == 0)
		return (0);
	return (str);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*str;

	(void) ac;
	fd = open(av[1], O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	return (0);
}
