/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintfptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:02:39 by cristian          #+#    #+#             */
/*   Updated: 2023/07/29 12:50:16 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_len_ptr(unsigned long long nb)
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

void	ft_put_ptr(unsigned long long ptr)
{
	if (ptr == 0)
		write (1, "0", 1);
	else
	{
		if (ptr >= 16)
		{
			ft_put_ptr(ptr / 16);
			ft_put_ptr(ptr % 16);
		}
		else
		{
			if (ptr <= 9)
				ft_putchar_pf(ptr + '0');
			else
				ft_putchar_pf(ptr + 'W');
		}
	}
}

int	ft_print_ptr(void *ptr)
{
	int	len;

	len = write(1, "0x", 2);
	if ((int)ptr == 0)
		len += write(1, "0", 1);
	else
	{
		len += ft_len_ptr((unsigned long long)ptr);
		ft_put_ptr((unsigned long long)ptr);
	}
	return (len);
}
