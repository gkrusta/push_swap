/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:19:25 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/05 16:06:28 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* libraries used */
# include <unistd.h>
# include <stdarg.h>

/* functions used */
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_decimal(long n);
int	ft_us_decimal(unsigned int n);
int	ft_hexadec(unsigned long long n, char c);
int	ft_void_ptr(unsigned long long n);
int	ft_printf(char const *str, ...);

#endif