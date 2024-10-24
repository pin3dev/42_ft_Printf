/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:42:25 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/24 21:26:13 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Processes a format specifier and prints the corresponding argument from the variadic list.
 *
 * @param args A va_list containing the arguments passed to ft_printf.
 * @param specifier A character representing the format specifier (e.g., 'd', 's', 'x').
 *
 * This function matches the format specifier (e.g., 'd', 's', 'x') with the appropriate printing
 * function. 
 * It handles specifiers for:
 *  	- Integers ('d', 'i');
 * 		- Characters ('c');
 * 		- Strings ('s');
 * 		- Unsigned integers ('u');
 * 		- Pointers ('p');
 * 		- Hexadecimal numbers ('x', 'X');
 * 		- literal '%' character('%')
 * For each specifier, it retrieves the corresponding argument from
 * the va_list using va_arg and calls the appropriate helper function (e.g., ft_putnbr_v2, print_pointer).
 *
 * @return The number of characters printed for the given argument.
 */
int	ck_format(va_list args, char specifier)
{
	int	x;

	x = 0;
	if (specifier == 'i' || specifier == 'd')
		x = ft_putnbr_v2(va_arg(args, int));
	else if (specifier == 'c')
		x = ft_putchar_v2(va_arg(args, int));
	else if (specifier == 's')
		x = ft_putstr_v2(va_arg(args, char *));
	else if (specifier == 'u')
		x = print_unsig(va_arg(args, unsigned int));
	else if (specifier == 'p')
		x = print_pointer(va_arg(args, unsigned long long));
	else if (specifier == 'x' || specifier == 'X')
		x = print_hex(specifier, va_arg(args, unsigned int));
	else if (specifier == '%')
		x = ft_putchar_v2('%');
	return (x);
}

/**
 * @brief Prints a formatted string to stdout, similar to the standard printf function in C.
 *
 * @param format A format string that contains the text to be printed and format specifiers.
 *               Format specifiers start with '%' and indicate the type of argument (e.g., %d, %s, %x).
 *               Example: "Text: %s, Number: %d\n".
 * @param ... Variadic arguments corresponding to the format specifiers in the format string.
 *            These arguments are captured using va_list and processed based on the format specifier.
 *
 * This function loops through the format string and prints characters until it encounters a format specifier ('%').
 * When a specifier is found, the ck_format function is called to handle the conversion and print the
 * corresponding argument. If no specifier is found, the character is printed directly.
 *
 * @return The total number of characters printed.
 */
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
			len += ck_format(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar_v2(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
