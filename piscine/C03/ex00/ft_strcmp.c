/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:55:31 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/19 17:37:20 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
