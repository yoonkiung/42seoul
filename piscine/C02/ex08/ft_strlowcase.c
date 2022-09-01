/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:24:01 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/16 15:50:50 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;
	int	todown;

	i = 0;
	todown = 'a' - 'A';
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += todown;
		i++;
	}
	return (str);
}
