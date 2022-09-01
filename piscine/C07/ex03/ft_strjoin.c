/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:42:00 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/28 20:16:27 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	need_memory(int size, char **strs, char *sep)
{
	int	i;
	int	ans;

	i = 0;
	ans = 0;
	while (i < size)
		ans += ft_strlen(strs[i++]);
	ans += ft_strlen(sep) * (size - 1);
	return (ans);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*new;
	 int	i;
	char	*read_head;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	i = need_memory(size, strs, sep);
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (!new)
		return (0);
	read_head = new;
	i = 0;
	while (i < size)
	{
		ft_strcpy(read_head, strs[i]);
		read_head += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(read_head, sep);
			read_head += ft_strlen(sep);
		}
		i++;
	}
	*read_head = '\0';
	return (new);
}
