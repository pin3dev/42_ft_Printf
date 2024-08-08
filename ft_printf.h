/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:44:18 by ivbatist          #+#    #+#             */
/*   Updated: 2022/12/23 22:44:52 by ivbatist         ###   ########.fr       */
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

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_print_hex(unsigned int n, int c);
int	ft_print_pointer(unsigned long long ptr);
int	ft_print_unsig(unsigned int n, int fd);
int	ft_putnbr(int n, int fd);
int	ft_printf(const char *format, ...);
int	ft_putchar_fd(char c, int fd);

#endif