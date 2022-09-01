/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:39:30 by kiyoon            #+#    #+#             */
/*   Updated: 2021/11/24 19:43:33 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	splitnum(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	if (s[i - 1] == c)
		count--;
	return (count + 1);
}

static char	**ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	check_start(char **temp, char const *s, int i, int start)
{
	*temp = (char *)malloc(sizeof(char) * (i - start + 1));
	if (!*temp)
		return (0);
	ft_strlcpy(*temp, &s[start], i - start + 1);
	return (1);
}

static int	toput(char **temp, char const *s, char c)
{
	int	i;
	int	start;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	start = i;
	while (s[i])
	{
		if (s[i] == c)
		{
			*temp = (char *)malloc(sizeof(char) * (i - start + 1));
			if (!*temp)
				return (0);
			ft_strlcpy(*temp++, &s[start], i - start + 1);
			while (s[i] == c)
				i++;
			start = i--;
		}
		i++;
	}
	if (s[start] && !check_start(temp++, s, i, start))
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**set;
	char	**temp;
	int		i;

	if (!s)
		return (NULL);
	if (!*s)
	{
		set = (char **)ft_calloc(1, sizeof(char *));
		if (!set)
			return (NULL);
		return (set);
	}
	set = (char **)ft_calloc(splitnum(s, c) + 1, sizeof(char *));
	if (!set)
		return (NULL);
	temp = set;
	i = 0;
	if (!toput(temp, s, c))
	{
		ft_free(set);
		return (NULL);
	}
	return (set);
}
