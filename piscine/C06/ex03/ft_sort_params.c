/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:19:45 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/23 09:57:32 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	calsize(char *s1, char *s2, int *size1, int *size2);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	size1;
	int	size2;

	i = 0;
	calsize(s1, s2, &size1, &size2);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (size1 == size2)
		return (0);
	else
		return (s1[i] - s2[i]);
}

void	calsize(char *s1, char *s2, int *size1, int *size2)
{
	int	i;
	int	siz1;
	int	siz2;

	i = 0;
	siz1 = 0;
	siz2 = 0;
	while (s1[i])
	{
		siz1++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		siz2++;
		i++;
	}
	*size1 = siz1;
	*size2 = siz2;
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	sort(char **argv, int argc)
{
	 int	i;
	 int	j;
	char	*temp;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) >= 0)
			{
				temp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	sort(argv, argc);
	i = 1;
	while (i < argc)
	{
		print_str(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
