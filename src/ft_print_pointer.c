/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:45:49 by ivbatist          #+#    #+#             */
/*   Updated: 2024/09/21 00:31:27 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft/inc/libft.h"

int	ft_length_pointer(uintptr_t n)
{
	size_t	length;

	length = 0;
	while (n != 0)
	{
		length++;
		n = n / 16;
	}
	return (length);
}


void	ft_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_ptr(ptr / 16);
		ft_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + 48), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	i;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	i = 2;
	ft_ptr(ptr);
	i += ft_length_pointer(ptr);
	return (i);
}
