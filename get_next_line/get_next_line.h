/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:19:05 by kiyoon            #+#    #+#             */
/*   Updated: 2021/12/03 11:47:15 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s1);

int		isin(char *str, char c);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
