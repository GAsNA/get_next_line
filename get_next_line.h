/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:03:44 by rleseur           #+#    #+#             */
/*   Updated: 2021/12/02 12:09:23 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

	/* get_next_line.c */
char	*get_next_line(int fd);

	/* get_next_line_utils.c */
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
int		get_index_backslash_n(char *s);
char	*ft_strcat(char *dst, char *src, int index);
char	*ft_strjoin(char *dst, char *src, int index);

#endif
