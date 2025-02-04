/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:41:15 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/26 12:26:44 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_helper(const char *format, va_list args, int *ret)
{
	long	arg;

	arg = 0;
	if (*format == 'c')
		*ret += ft_putchar_fd(va_arg(args, int), 1);
	else if (*format == 's')
		*ret += ft_putstr_fd(va_arg(args, char *), 1);
	else if (*format == 'p')
	{
		*ret += ft_putstr_fd("0x", 1);
		*ret += ft_nbr((unsigned long)va_arg(args, void *), "0123456789abcdef");
	}
	else if (*format == 'd' || *format == 'i')
	{
		arg = va_arg(args, int);
		if (arg < 0)
		{
			arg = -arg;
			*ret += ft_putchar_fd('-', 1);
		}
		*ret += ft_nbr((unsigned long)arg, "0123456789");
	}
	else if (*format == 'u')
		*ret += ft_nbr(va_arg(args, unsigned int), "0123456789");
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args;

	if (write(1, NULL, 0) == -1)
		return (-1);
	va_start(args, format);
	ret = 0;
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1))
		{
			ft_printf_helper(++format, args, &ret);
			if (*format == 'x')
				ret += ft_nbr(va_arg(args, unsigned int), "0123456789abcdef");
			else if (*format == 'X')
				ret += ft_nbr(va_arg(args, unsigned int), "0123456789ABCDEF");
			else if (*format == '%')
				ret += ft_putchar_fd('%', 1);
		}
		else if (*format != '%')
			ret += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (ret);
}
