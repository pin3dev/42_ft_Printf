/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsig.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:48:58 by ivbatist          #+#    #+#             */
/*   Updated: 2024/09/25 15:08:04 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../42_Libft/libft/inc/libft.h"

/**
 * @brief Calculates the number of digits in an unsigned integer.
 *
 * @param n The unsigned integer to analyze.
 *
 * This function determines how many digits are required to represent
 * the given unsigned integer 'n' in decimal notation. It repeatedly
 * divides 'n' by 10 until the value is reduced to 0, counting the number
 * of divisions.
 *
 * @return The number of digits in the unsigned integer 'n'.
 */
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

/**
 * @brief Prints an unsigned integer to the standard output (stdout).
 *
 * @param n The unsigned integer to be printed.
 *
 * This function prints an unsigned integer 'n' by first calculating its length
 * in decimal digits using `unsig_number`. It then allocates memory for a character
 * array to store the digits, converts the number to a string, and prints it.
 * If the value of 'n' is 0, it directly prints '0'. After printing, the allocated
 * memory is freed.
 *
 * @return The number of characters printed.
 */
int	print_unsig(unsigned int n)
{
	unsigned int	d;
	int				length;
	char			*c;

	if (n == 0)
		return (write (STDOUT_FILENO, "0", 1));
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
	write(STDOUT_FILENO, c, length);
	free(c);
	return (length);
}
