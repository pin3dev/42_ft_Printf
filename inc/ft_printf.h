/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:44:18 by ivbatist          #+#    #+#             */
/*   Updated: 2024/09/21 00:46:03 by pin3dev          ###   ########.fr       */
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

int	ft_print_hex(unsigned int n, int c);
int	ft_print_pointer(unsigned long long ptr);
int	ft_print_unsig(unsigned int n, int fd);
int	ft_printf(const char *format, ...);

int	ft_putchar_v2(char c);
int	ft_putstr_v2(char *s);
int	ft_putnbr_v2(int n);    

#endif
