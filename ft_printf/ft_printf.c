/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 09:21:05 by kiyoon            #+#    #+#             */
/*   Updated: 2022/01/05 17:29:06 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_tag(const char *format)
{
	int	i;
	int	count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}

int	is_tag(char c, char *tag)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
	{
		*tag = c;
		return (1);
	}
	return (0);
}

int	exist_tag(char *format, va_list ap)
{
	char	tag;

	is_tag(format[1], &tag);
	if (tag == 'c')
		return (print_c(ap));
	else if (tag == 's')
		return (print_s(ap));
	else if (tag == 'p')
		return (print_p(ap));
	else if (tag == 'd' || tag == 'i')
		return (print_d(ap));
	else if (tag == 'u')
		return (print_u(ap));
	else if (tag == 'x')
		return (print_x(ap));
	else if (tag == 'X')
		return (print_xx(ap));
	else if (tag == '%')
		return (write(1, "%", 1));
	return (0);
}

int	to_print(const char *format, va_list ap)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			temp = exist_tag((char *)&format[i], ap);
			count += temp;
			i++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		num_tag;
	int		len;

	num_tag = count_tag(format);
	if (num_tag < 0)
		len = 0;
	else if (num_tag == 0)
	{
		ft_putstr_fd((char *)format, 1);
		len = ft_strlen(format);
	}
	else
	{
		va_start(ap, format);
		len = to_print(format, ap);
		va_end(ap);
	}
	return (len);
}
