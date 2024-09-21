/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:33:06 by pin3dev           #+#    #+#             */
/*   Updated: 2024/09/21 00:43:31 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft/inc/libft.h"

int	ft_putchar_v2(char c)
{
	return(write(1, &c, STDOUT_FILENO));
}

int	ft_putstr_v2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
		i += ft_putchar_v2(s[i]);
	return (i);
}

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