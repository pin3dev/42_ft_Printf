/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:45:09 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/24 21:26:13 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Recursively prints a number in hexadecimal format.
 *
 * @param n The number to be printed in hexadecimal.
 * @param c Specifies whether the hexadecimal letters should be lowercase ('x') or uppercase ('X').
 *
 * This function recursively converts the given number 'n' into its hexadecimal representation.
 * If 'n' is greater than or equal to 16, the function continues to divide the number, printing the 
 * remainders in reverse order. It uses the ASCII values to print numbers (0-9) and hexadecimal letters 
 * (a-f or A-F) based on the value of 'c'.
 *
 * @return The number of characters printed.
 */
int	print_hex_rec(unsigned long long n, int c)
{
    int count = 0;

    if (n >= 16)
    {
        count += print_hex_rec(n / 16, c);
        count += print_hex_rec(n % 16, c);
    }
    else
    {
        if (n <= 9)
            count += ft_putchar_v2((n + 48));
        else
        {
            if (c == 'x')
                count += ft_putchar_v2((n - 10 + 'a'));
            if (c == 'X')
                count += ft_putchar_v2((n - 10 + 'A'));
        }
    }

    return count;
}

/**
 * @brief Handles variadic arguments and prints a number in hexadecimal format.
 *
 * @param c Specifies whether the hexadecimal letters should be lowercase ('x') or uppercase ('X').
 * @param ... The variadic argument list containing the number to be printed as hexadecimal.
 *
 * This function retrieves an unsigned long long integer from the variadic arguments, then calls
 * `print_hex_rec` to print the number in hexadecimal format. It handles the format specifier for 
 * lowercase ('x') and uppercase ('X') hexadecimal letters.
 *
 * @return The number of characters printed.
 */
int	print_hex_varargs(int c, ...)
{
    va_list args;
    unsigned long long n;
    int count = 0;

    va_start(args, c);
    n = va_arg(args, unsigned long long);
    va_end(args);
    count = print_hex_rec(n, c);
    return count;
}

