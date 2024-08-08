/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:48:58 by ivbatist          #+#    #+#             */
/*   Updated: 2022/12/23 22:49:42 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned	int	unsig_number(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_print_unsig(unsigned int n, int fd)
{
	unsigned int	d;
	int				length;
	char			*c;

	if (n == 0)
		return (write (fd, "0", 1));
	d = unsig_number(n);
	length = d;
	c = malloc((d + 1) * sizeof(char));
	c[d--] = '\0';
	if (n == 0)
		c[0] = '0';
	while (n != 0)
	{
		c[d--] = (n % 10) + 48;
		n = n / 10;
	}
	write(fd, c, length);
	free(c);
	return (length);
}