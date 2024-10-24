/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:45:49 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/24 21:26:13 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Prints a memory address (pointer) in hexadecimal format.
 *
 * @param ptr The memory address (pointer) to be printed.
 *
 * This function prints a pointer in hexadecimal format, prefixed with "0x". If the pointer is NULL 
 * (i.e., ptr == 0), it prints "(nil)" to indicate a null pointer. For non-null pointers, it converts 
 * the pointer to hexadecimal and prints the result prefixed with "0x".
 *
 * @return The total number of characters printed, including the "0x" prefix.
 */
int	print_pointer(unsigned long long ptr)
{
	int	count;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	count = 2;
	count += print_hex('x', ptr);
	return (count);
}
