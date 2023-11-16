/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:52:19 by cristian          #+#    #+#             */
/*   Updated: 2023/09/01 19:44:27 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_putchar_pf(int c);
int		ft_putstr_pf(char *str);
int		ft_number_digits(long int nb);
char	*ft_itoa(int n);
int		ft_putnbr(int nb);
int		ft_len_hex(unsigned int nb);
void	ft_put_hex(unsigned int nb, char const fmt);
int		ft_print_hex(unsigned int nb, char const fmt);
void	ft_put_ptr(unsigned long long ptr);
int		ft_len_ptr(unsigned long long nb);
int		ft_print_ptr(void *ptr);
int		ft_put_unsig(unsigned int nb);
int		ft_printf(char const *fmt, ...);

#endif
