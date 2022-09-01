/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:53:43 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/13 21:03:14 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c);

void	ft_print_combn(int n)
{









void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_print(char a, char b, char c, char d)
{
	char    blank;
	char    coma;

	blank = ' ';
        coma = ',';
        write(1, &a, 1);
        write(1, &b, 1);
        write(1, &blank, 1);
        write(1, &c, 1);
        write(1, &d, 1);
        if (a == '9' && b == '8' && c == '9' && d == '9')
                return ;
        write(1, &coma, 1);
	write(1, &blank, 1);
}

void    add(char *a, char *b, char *c, char *d)
{
         if (*b == '9')
         {
                 *c = *a + 1;
                 *d = '0';
         }
         else
         {
                 *c = *a;
                  *d = *b + 1;
}

