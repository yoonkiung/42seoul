/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:01:48 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/19 10:18:44 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_upperalph(char *c);
void	alph_up_down(char *c);
bool	is_num(char *c);
bool	is_alph(char *c);

char	*ft_strcapitalize(char *str)
{
	 int	i;
	bool	is_start;

	i = 0;
	is_start = true;
	while (str[i])
	{
		if (is_start)
		{
			if (is_alph(&str[i]))
			{
				if (!is_upperalph(&str[i]))
					alph_up_down(&str[i]);
				is_start = false;
			}
		}
		else if (!is_start && is_upperalph(&str[i]))
			alph_up_down(&str[i]);
		if (is_num(&str[i]))
			is_start = false;
		if (!((is_alph(&str[i])) || (is_num(&str[i]))))
			is_start = true;
		i++;
	}
	return (str);
}

bool	is_upperalph(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		return (true);
	return (false);
}

void	alph_up_down(char *c)
{
	int	toupdown;

	toupdown = 'a' - 'A';
	if (*c >= 'a' && *c <= 'z')
		*c -= toupdown;
	else
		*c += toupdown;
}

bool	is_num(char *c)
{
	if (*c >= '0' && *c <= '9')
		return (true);
	return (false);
}

bool	is_alph(char *c)
{
	if ((*c >= 'A' && *c <= 'Z') || (*c >= 'a' && *c <= 'z'))
		return (true);
	return (false);
}
