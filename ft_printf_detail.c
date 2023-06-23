/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_detail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryoo <mryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:16:42 by mryoo             #+#    #+#             */
/*   Updated: 2023/06/23 12:16:32 by mryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_s(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		len = 6;
		return (len);
	}
	while (*str)
	{
		if (printf_c(*str) == -1)
			return (-1);
		len++;
		str++;
	}
	return (len);
}

int	printf_p(unsigned long long p)
{
	int		i;
	int		len;
	char	arr[20];

	i = 0;
	len = 0;
	if (printf_s("0x") == -1)
		return (-1);
	while (p >= 16)
	{
		arr[i] = "0123456789abcdef"[p % 16];
		p /= 16;
		i++;
	}
	arr[i] = "0123456789abcdef"[p];
	len = print_arr(arr, i, len);
	if (len == -1)
		return (-1);
	return (len + 2);
}

int	printf_di(long long n)
{
	int		i;
	int		len;
	char	arr[20];

	i = 0;
	len = 0;
	if (n < 0)
	{
		if (printf_c('-') == -1)
			return (-1);
		n *= -1;
		len++;
	}
	while (n >= 10)
	{
		arr[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	arr[i] = (n % 10) + 48;
	len = print_arr(arr, i, len);
	if (len == -1)
		return (-1);
	return (len);
}

int	printf_u(unsigned int n)
{
	int		i;
	int		len;
	char	arr[10];

	i = 0;
	len = 0;
	while (n >= 10)
	{
		arr[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	arr[i] = (n % 10) + 48;
	len = print_arr(arr, i, len);
	if (len == -1)
		return (-1);
	return (len);
}

int	printf_x(unsigned int n, char flag)
{
	int		i;
	int		len;
	char	arr[10];
	char	*hexa;

	i = 0;
	len = 0;
	if (flag == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	while (n >= 16)
	{
		arr[i] = hexa[n % 16];
		n /= 16;
		i++;
	}
	arr[i] = hexa[n];
	len = print_arr(arr, i, len);
	if (len == -1)
		return (-1);
	return (len);
}
