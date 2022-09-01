/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:18:21 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/15 13:23:09 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;
	int	toup;

	i = 0;
	toup = 'a' - 'A';
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= toup;
		i++;
	}
	return (str);
}
