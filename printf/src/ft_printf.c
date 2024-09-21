/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:42:25 by ivbatist          #+#    #+#             */
/*   Updated: 2024/09/21 00:52:39 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft/inc/libft.h"

int	ft_format(va_list args, char specification)
{
	int	x;

	x = 0;
	if (specification == 'i' || specification == 'd')
		x = ft_putnbr_v2(va_arg(args, int));
	else if (specification == 'c')
		x = ft_putchar_v2(va_arg(args, int));
	else if (specification == 's')
		x = ft_putstr_v2(va_arg(args, char *));
	else if (specification == 'u')
		x = ft_print_unsig(va_arg(args, unsigned int), 1);
	else if (specification == 'p')
		x = ft_print_pointer(va_arg(args, unsigned long long));
	else if (specification == 'x')
		x = ft_print_hex(va_arg(args, unsigned int), specification);
	else if (specification == 'X')
		x = ft_print_hex(va_arg(args, unsigned int), specification);
	else if (specification == '%')
		x = ft_putchar_v2('%');
	return (x);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	size_t	i;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar_v2(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
