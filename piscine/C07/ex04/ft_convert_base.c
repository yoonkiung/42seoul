/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:46:02 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/30 01:32:15 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		init(int *n, char *base_from, char *base_to, char *nbr);
void	init_nb(unsigned int *nb, int *n);

int	match(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
}

int	base_len(char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| match(base[i], base + i + 1) >= 0
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
	if (i < 2)
		return (0);
	return (i);
}

int	ft_atoi_base(char *str, char *base, int size)
{
	int	i;
	int	n;
	int	min;
	int	j;

	j = 0;
	while ((str[j] >= 9 && str[j] <= 13) || str[j] == ' ')
		j++;
	min = 1;
	while (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			min *= -1;
		j++;
	}
	n = 0;
	i = match(str[j++], base);
	while (i >= 0)
	{
		n = n * size + i;
		i = match(str[j++], base);
	}
	return (n * min);
}

int	ft_nbrlen(unsigned int n, unsigned int base_size)
{
	if (n < base_size)
		return (1);
	return (1 + ft_nbrlen(n / base_size, base_size));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	nb;
	int				size;
	int				n;
	int				i;
	char			*dest;

	if (!init(&n, base_from, base_to, nbr))
		return (0);
	size = base_len(base_to);
	init_nb(&nb, &n);
	i = ft_nbrlen(nb, size);
	if (n < 0)
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	dest[i] = '\0';
	while (i--)
	{
		dest[i] = base_to[nb % size];
		nb /= size;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
