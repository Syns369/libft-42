/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdarcour <jdarcour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:23:17 by jdarcour          #+#    #+#             */
/*   Updated: 2023/02/27 00:09:18 by jdarcour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include "stdarg.h"

# ifndef UPPER_HEX
#  define UPPER_HEX "0123456789ABCDEF"
# endif

# ifndef LOWER_HEX
#  define LOWER_HEX "0123456789abcdef"
# endif

# ifndef DECIMAL
#  define DECIMAL "0123456789"
# endif

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_pointer(unsigned long nb);
int	ft_print_arg(const char format, va_list args);
int	ft_putnbr(int nb);
int	ft_putnbr_base(unsigned long nb, char *base);

#endif