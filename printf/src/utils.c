/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:33:06 by pin3dev           #+#    #+#             */
/*   Updated: 2024/09/25 15:12:50 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft/inc/libft.h"

/**
 * @brief Writes a single character to the standard output (stdout).
 *
 * @param c The character to be printed.
 *
 * This function writes the character 'c' to the standard output (stdout) using the write system call.
 * It is a basic utility function used by other functions to print characters.
 *
 * @return The number of characters written (always 1, since it writes one character).
 */
int	ft_putchar_v2(char c)
{
	return(write(STDOUT_FILENO, &c, 1));
}

/**
 * @brief Writes a string to the standard output (stdout).
 *
 * @param s The string to be printed.
 *
 * This function prints a string by iterating through each character and calling ft_putchar_v2 for each.
 * If the string is NULL, it prints "(null)" to indicate the absence of a valid string.
 *
 * @return The number of characters printed.
 */
int	ft_putstr_v2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(STDOUT_FILENO, "(null)", 6));
	while (s[i] != '\0')
		i += ft_putchar_v2(s[i]);
	return (i);
}

/**
 * @brief Writes an integer to the standard output (stdout).
 *
 * @param n The integer to be printed.
 *
 * This function converts the integer 'n' to its string representation using ft_itoa,
 * and then prints each character using ft_putchar_v2. After printing, it frees the memory
 * allocated for the string representation.
 *
 * @return The number of characters printed.
 */
int	ft_putnbr_v2(int n)
{
	char	*s;
	int		i;

	s = ft_itoa(n);
	i = 0;
	while (s[i] != '\0')
		i += ft_putchar_v2(s[i]);
	free(s);
	return (i);
}