/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:55:28 by rleseur           #+#    #+#             */
/*   Updated: 2021/12/10 14:10:41 by rleseur          ###   ########.fr       */
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
	int		i;
	char	*str;

	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
		str[len_s1 + i] = s2[i];
	str[len_s1 + len_s2] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
	}
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;
	size_t			j;
	unsigned int	to_malloc;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	to_malloc = ft_strlen(s + start);
	if (to_malloc > len)
		to_malloc = len;
	res = malloc((to_malloc + 1) * sizeof(char));
	if (!res)
		return (0);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (i >= start && j < len)
			res[j++] = s[i];
	}
	res[j] = '\0';
	return (res);
}
