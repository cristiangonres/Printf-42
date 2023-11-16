/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintfunsig.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:15:29 by cristian          #+#    #+#             */
/*   Updated: 2023/07/29 12:51:34 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_uitoa(unsigned int nb)
{
	char	*str;
	int		len;

	len = ft_number_digits(nb);
	str = (char *) malloc(sizeof(char) * (len +1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}

int	ft_put_unsig(unsigned int nb)
{
	char	*num;
	int		len;

	len = 0;
	if (nb == 0)
	{
		len = 1;
		write(1, "0", 1);
	}
	else
	{
		num = ft_uitoa(nb);
		len = ft_putstr_pf(num);
		free(num);
	}
	return (len);
}
