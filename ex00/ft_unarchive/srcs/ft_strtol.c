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

#include "libft.h"

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

/*
** @brief      Control for overflow/underflow. If it occures, shrink number to
**             corresponding LONG_MIN or LONG_MAX. Both long int and long long
**             have sizeof() == 8, which is somehow unexpected.
**
**             Magic numbers:
**
**             922337203685477580 - LONG_MAX_BASE (without the last digit)
**             9223372036854775807 - LONG_MAX
** @param      res    The resource
** @param      sign   The sign
** @param      digit  The digit
** @param      base   The base
**
** @return     True if overflow, False otherwise.
*/

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

/*
** @brief      Convert the string in str to a long value
**
**             The string may begin with an arbitrary amount of white space
**             followed by a single optional '+' or '-' sign. If base is zero or
**             16, the string may then include a '0x' prefix (base 16); if next
**             char is 0, the number will be read in base 8. The remainder of
**             the string is converted to a long, stopping at the first charated
**             that is not valid int the given base.
**
**
**             If endpty is not NULL, strtol() stores the address of the first
**             invalid characted in *endptr. If there was no digits at all,
**             strtol() stores the original value of str in *endptr. Thus, if
**             *str != '\0' but **endptr is '\0' on return, the entire string
**             was valid.
**
**             If an overflow or underflow occurs, the function return value is
**             clumped to the LONG_MIN or LONG_MAX, correspondingly.
**
**             Since we're restricted in usage of external libraries, limits are
**             hadrcoded:
**
**             32 bit compiler  |    64 bit compiler
**	LONG_MIN     -2147483648    |  -9223372036854775808
**	LONG_MAX      2147483647    |   9223372036854775807
**
**
**
** @param      str     The string
** @param      endptr  The endptr
** @param      base    The base
**
** @return     the result of the conversion, unless undeflow or overflow
**             occurred
*/

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
