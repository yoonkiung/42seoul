/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:27:34 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/21 19:05:20 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_sqrt(int nb)
{
	unsigned int	i;

	i = 0;
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	while (i * i <= (unsigned int)nb)
		i++;
	return (i);
}

int	ft_is_prime(int nb)
{
	unsigned int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	else if (nb == 2)
		return (1);
	else
	{
		while (i <= ft_sqrt(nb))
		{
			if ((unsigned int)nb % i == 0)
				return (0);
			i++;
		}
		return (1);
	}
}
