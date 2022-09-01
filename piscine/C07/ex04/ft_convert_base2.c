/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:48:37 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/30 01:30:06 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_len(char *base);
int	ft_atoi_base(char *str, char *base, int size);

int	init(int *n, char *base_from, char *base_to, char *nbr)
{
	*n = base_len(base_from);
	if (*n == 0 || base_len(base_to) == 0)
		return (0);
	*n = ft_atoi_base(nbr, base_from, *n);
	return (1);
}

void	init_nb(unsigned int *nb, int *n)
{
	if (*n < 0)
		*nb = -(*n);
	else
		*nb = *n;
}
