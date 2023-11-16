/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintfhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:40:10 by cristian          #+#    #+#             */
/*   Updated: 2023/07/29 12:48:50 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_len_hex(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

void	ft_put_hex(unsigned int nb, char const fmt)
{
	if (nb >= 16)
	{
		ft_put_hex(nb / 16, fmt);
		ft_put_hex(nb % 16, fmt);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_pf(nb + '0');
		else
		{
			if (fmt == 'x')
				ft_putchar_pf(nb + 'W');
			if (fmt == 'X')
				ft_putchar_pf(nb + '7');
		}
	}
}

int	ft_print_hex(unsigned int nb, char const fmt)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = write(1, "0", 1);
	else
	{
		ft_put_hex(nb, fmt);
		len = ft_len_hex(nb);
	}
	return (len);
}
