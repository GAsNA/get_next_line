/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:14:02 by rleseur           #+#    #+#             */
/*   Updated: 2021/12/02 15:56:45 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

int	get_index_backslash_n(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			return (i);
	}
	return (i);
}

char	*ft_strcat(char *dst, char *src, int index)
{
	int	i;
	int	len_d;

	len_d = ft_strlen(dst);
	i = -1;
	while (src[++i] && i < index)
		dst[len_d + i] = src[i];
	return (dst);
}

char	*ft_strjoin(char *dst, char *src, int index)
{
	char	*tmp;
	int		len;

	len = ft_strlen(dst);
	tmp = ft_strdup(dst);
	if (!tmp)
		return (0);
	free(dst);
	len += index + 1;
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (0);
	ft_strcat(dst, tmp, BUFFER_SIZE);
	ft_strcat(dst, src, index);
	return (dst);
}
