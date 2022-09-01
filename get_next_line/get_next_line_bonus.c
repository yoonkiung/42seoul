/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:44:57 by kiyoon            #+#    #+#             */
/*   Updated: 2021/12/03 11:48:16 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*makestr(char **s, int byte)
{
	char	*ret;
	char	*temp;
	int		i;

	if (!*s || byte == -1)
		return (NULL);
	i = isin(*s, '\n');
	if (i != -1)
	{
		ret = ft_substr(*s, 0, i);
		temp = ft_substr(*s, i + 1, ft_strlen(*s));
		free(*s);
		*s = temp;
		if (**s != '\0')
			return (ret);
	}
	else
		ret = ft_strdup(*s);
	free(*s);
	*s = NULL;
	return (ret);
}

int	this_is_first(char **s)
{
	*s = ft_strdup("");
	if (!*s)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*s[OPEN_MAX];
	int			byte;
	char		temp[BUFFER_SIZE + 1];
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	byte = read(fd, temp, BUFFER_SIZE);
	while (byte > 0)
	{
		temp[byte] = '\0';
		if (!s[fd])
			if (!this_is_first(&s[fd]))
				return (NULL);
		str = ft_strjoin(s[fd], temp);
		free(s[fd]);
		if (!str)
			return (NULL);
		s[fd] = str;
		if (isin(s[fd], '\n') != -1)
			break ;
		byte = read(fd, temp, BUFFER_SIZE);
	}
	return (makestr(&s[fd], byte));
}
