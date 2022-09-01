/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:55:31 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/18 22:33:17 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = 0;
	src_len = 0;
	while (*dest != '\0')
	{
		dest++;
		dest_len++;
	}
	while (*src != '\0' && dest_len + src_len + 1 < size)
	{
		*dest++ = *src++;
		src_len++;
	}
	*dest = '\0';
	while (*src++ != '\0')
		src_len++;
	if (size <= dest_len)
		return (src_len + size);
	else
		return (src_len + dest_len);
}
