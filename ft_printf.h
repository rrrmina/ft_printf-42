/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryoo <mryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:57:55 by mryoo             #+#    #+#             */
/*   Updated: 2023/06/23 11:57:01 by mryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	check_argument(va_list *ap, const char str);
int	ft_print(char *c, int i, int len);
int	print_arr(char *c, int i, int len);
int	printf_c(char c);
int	printf_s(char *str);
int	printf_p(unsigned long long p);
int	printf_di(long long n);
int	printf_u(unsigned int n);
int	printf_x(unsigned int n, char flag);

#endif
