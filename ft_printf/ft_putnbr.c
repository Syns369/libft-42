/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdarcour <jdarcour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:40:21 by jdarcour          #+#    #+#             */
/*   Updated: 2023/02/27 00:01:19 by jdarcour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	print_len;

	print_len = 0;
	if (nb == -2147483648)
	{
		print_len += ft_putstr("-2147483648");
		return (print_len);
	}
	if (nb < 0)
	{
		print_len += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		print_len += ft_putnbr(nb / 10);
		print_len += ft_putnbr(nb % 10);
	}
	else
		print_len += ft_putchar(nb + '0');
	return (print_len);
}

int	ft_putnbr_base(unsigned long nb, char *base)
{
	int	print_len;
	int	base_len;

	print_len = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nb >= (unsigned long)base_len)
	{
		print_len += ft_putnbr_base(nb / base_len, base);
		print_len += ft_putnbr_base(nb % base_len, base);
	}
	else
		print_len += ft_putchar(base[nb]);
	return (print_len);
}
