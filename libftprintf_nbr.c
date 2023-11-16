/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintfnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:54:21 by cristian          #+#    #+#             */
/*   Updated: 2023/07/28 14:40:09 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	char	*num;
	int		len;

	num = ft_itoa(nb);
	len = ft_putstr_pf(num);
	free(num);
	return (len);
}
