/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:24:27 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/21 19:01:41 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	i;

	i = 0;
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	while (i * i <= (unsigned int)nb)
	{
		if (i * i == (unsigned int)nb)
			return ((int)i);
		i++;
	}
	return (0);
}
