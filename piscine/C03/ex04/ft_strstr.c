/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:25:02 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/18 20:49:11 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>

bool	is_same(char *a, char *b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (false);
		i++;
	}
	return (true);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = ft_strlen(str);
	j = ft_strlen(to_find);
	if (j == 0)
		return (str);
	while (i >= j)
	{
		i--;
		if (is_same(str, to_find, j))
			return (str);
		str++;
	}
	return (0);
}
