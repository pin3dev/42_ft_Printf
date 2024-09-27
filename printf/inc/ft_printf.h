/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:44:18 by ivbatist          #+#    #+#             */
/*   Updated: 2024/09/27 13:52:05 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include <stdbool.h>
# include "../../../42_Libft/libft/inc/libft.h"


/**
 * @brief Macro to handle printing of unsigned integers in hexadecimal format.
 *
 * @param c Specifies whether the hexadecimal letters should be lowercase ('x') or uppercase ('X').
 * @param n The number to be printed in hexadecimal.
 *
 * This macro checks the size of the number 'n'. If the number is of type `unsigned int` (32-bit),
 * it casts the number to `unsigned long long` and calls `print_hex_varargs` to ensure compatibility.
 * For larger numbers (64-bit), it directly calls `print_hex_varargs` with the appropriate casting.
 */
#define print_hex(c, n) ((sizeof(n) == sizeof(unsigned int)) ? \
    print_hex_varargs(c, (unsigned long long)(unsigned int)n) : \
    print_hex_varargs(c, (unsigned long long)n))
    
int	print_hex_varargs(int c, ...);
int	print_pointer(unsigned long long ptr);
int	print_unsig(unsigned int n);
int	ft_printf(const char *format, ...);

int	ft_putchar_v2(char c);
int	ft_putstr_v2(char *s);
int	ft_putnbr_v2(int n);    

#endif
