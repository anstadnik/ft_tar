/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:16:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:26:20 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00.h"

static int	get_digit(char c, int base)
{
	if (base >= 2 && base <= 10)
		return (ft_isdigit(c) ? c - '0' : -1);
	else if (base <= 36)
	{
		if (ft_isdigit(c))
			return (c - '0');
		else
		{
			if (c >= 65 && c <= 90)
				return (10 + c - 'A');
			else if (c >= 97 && c <= 122)
				return (10 + c - 'a');
		}
	}
	return (-1);
}

static long	is_overflow(unsigned long res, int sign, int digit, int base)
{
	unsigned long	long_max_base;
	long			long_max;

	long_max_base = 922337203685477580;
	long_max = 9223372036854775807;
	if (res >= long_max_base)
	{
		if (res == long_max_base && digit <= 7)
			return (sign * (res * base + digit));
		return (sign == 1 ? long_max : -long_max - 1);
	}
	return (0);
}

long		ft_strtol(const char *str, char **endptr, int base)
{
	int				sign;
	int				digit;
	unsigned long	res;
	long			overflow;

	if (endptr != NULL)
		*endptr = (char *)str;
	res = 0;
	if (base < 2 || base > 36)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = *str == '-' ? -1 : 1;
	*str == '-' || *str == '+' ? str++ : 0;
	while ((digit = get_digit(*str++, base)) != -1 && digit < base)
	{
		if (endptr)
			*endptr = (char *)str;
		if ((overflow = is_overflow(res, sign, digit, base)) != 0)
			return (overflow);
		res = res * base + digit;
	}
	return (sign * res);
}
