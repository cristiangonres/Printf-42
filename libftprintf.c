/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:44:11 by cristian          #+#    #+#             */
/*   Updated: 2023/08/29 12:35:55 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_fmt(char const c, va_list args)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret = ft_putchar_pf(va_arg(args, int));
	else if (c == 's')
		ret = ft_putstr_pf(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		ret = ft_putnbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		ret = ft_print_hex(va_arg(args, unsigned long), c);
	else if (c == 'p')
		ret = ft_print_ptr(va_arg(args, void *));
	else if (c == 'u')
		ret = ft_put_unsig(va_arg(args, unsigned int));
	else if (c == '%')
		ret += ft_putchar_pf(c);
	return (ret);
}

int	ft_printf(char const *fmt, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, fmt);
	i = 0;
	len = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[i + 1] == '\0')
				break ;
			len += ft_fmt(fmt[++i], args);
		}
		else
			len += ft_putchar_pf(fmt[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int main (void)
{
	int ft = 0;
	int x = 0;

	x =     printf("%%hola");
	ft = ft_printf("%%hola%");
	printf("Printf = %d\n", x);
	printf("FT     = %d\n", ft);

	return (0);
}