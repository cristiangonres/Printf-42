/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintfstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:02:59 by cristian          #+#    #+#             */
/*   Updated: 2023/07/28 14:40:14 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar_pf(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_pf(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write(1, str++, 1);
		len++;
	}
	return (len);
}

int	ft_number_digits(long int nb)
{
	int	digits;

	digits = 1;
	if (nb < 0)
	{
		nb *= -1;
		digits++;
	}
	while (nb > 9)
	{
		nb /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	i;
	long int	nb;

	nb = n;
	i = ft_number_digits(nb);
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (0);
	str[i--] = 0;
	if (nb == 0)
		str[0] = 48;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
