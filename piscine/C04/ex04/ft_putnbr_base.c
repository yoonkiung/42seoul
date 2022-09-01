/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:06:55 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/21 16:18:25 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	what_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	allunique(char *str)
{	
	 int	i;
	 int	j;
	 int	l;

	l = what_base(str);
	i = 0;
	while (i < l - 1)
	{
		j = i + 1;
		while (j < l)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	search(char *base)
{
	int	i;

	i = 0;
	if (what_base(base) == 1 || what_base(base) == 0)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_positive(int nbr, char *base, int base_num)
{
	if (nbr > base_num - 1)
		ft_positive(nbr / base_num, base, base_num);
	write(1, &(base[nbr % base_num]), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_num;

	base_num = what_base(base);
	if (allunique(base) && search(base))
	{
		if (nbr >= 0)
			ft_positive(nbr, base, base_num);
		else if (nbr == -2147483648)
		{
			ft_putnbr_base(nbr / base_num, base);
			write(1, &base[-(nbr % base_num)], 1);
		}
		else
		{
			write(1, "-", 1);
			ft_putnbr_base(-nbr, base);
		}
	}
}
