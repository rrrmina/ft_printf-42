/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryoo <mryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:16:49 by mryoo             #+#    #+#             */
/*   Updated: 2023/06/23 11:23:20 by mryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_c(char c)
{
	int	len;

	len = 1;
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len);
}

int	print_arr(char *c, int i, int len)
{
	while (i >= 0)
	{
		if (printf_c(c[i]) == -1)
			return (-1);
		i--;
		len++;
	}
	return (len);
}

int	check_argument(va_list *ap, const char str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len = printf_c((char)va_arg(*ap, int));
	else if (str == 's')
		len = printf_s(va_arg(*ap, char *));
	else if (str == 'p')
		len = printf_p(va_arg(*ap, unsigned long long));
	else if (str == 'd' || str == 'i')
		len = printf_di(va_arg(*ap, int));
	else if (str == 'u')
		len = printf_u(va_arg(*ap, unsigned int));
	else if (str == 'x')
		len = printf_x(va_arg(*ap, unsigned int), 'x');
	else if (str == 'X')
		len = printf_x(va_arg(*ap, unsigned int), 'X');
	else if (str == '%')
		len = printf_c('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		sum;

	sum = 0;
	va_start(ap, str);
	while (*str)
	{
		len = 1;
		if (*str == '%')
		{
			str++;
			len = check_argument(&ap, *str++);
			if (len == -1)
				return (-1);
		}
		else
		{
			if (printf_c(*str++) == -1)
				return (-1);
		}
		sum += len;
	}
	va_end(ap);
	return (sum);
}
