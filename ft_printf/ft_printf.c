/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdarcour <jdarcour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:18:29 by jdarcour          #+#    #+#             */
/*   Updated: 2023/04/08 17:32:32 by jdarcour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_pointer(unsigned long nb)
{
	int	print_len;

	if (!nb)
		return (ft_putstr("(nil)"));
	print_len = 0;
	print_len += ft_putstr("0x");
	print_len += ft_putnbr_base(nb, "0123456789abcdef");
	return (print_len);
}

int	ft_print_arg(const char format, va_list args)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_pointer(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		print_len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_putnbr_base(va_arg(args, unsigned int), DECIMAL);
	else if (format == 'x')
		print_len += ft_putnbr_base(va_arg(args, unsigned int), LOWER_HEX);
	else if (format == 'X')
		print_len += ft_putnbr_base(va_arg(args, unsigned int), UPPER_HEX);
	else if (format == '%')
		print_len += ft_putchar('%');
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_len += ft_print_arg(format[i + 1], args);
			i++;
		}
		else
			print_len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
