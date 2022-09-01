/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:54:47 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/19 20:22:27 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calsize(char *s1, char *s2, int *size1, int *size2);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				size1;
	int				size2;
	unsigned int	max;

	i = 0;
	max = calsize(s1, s2, &size1, &size2);
	if (max < n)
		n = max;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	i--;
	if (n == 0)
		return (0);
	else if (size1 == size2)
		return (0);
	else
		return (s1[i] - s2[i]);
}

int	calsize(char *s1, char *s2, int *size1, int *size2)
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
	if (siz1 >= siz2)
		return (siz1);
	else
		return (siz2);
}
