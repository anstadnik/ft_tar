/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:11:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:20:51 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Calculate the length of the resulting string, which is equivalent
**             to the size required to store it in the heap.
**
** @param      value  Value to be converted
** @param      base   The radix
**
** @return     The length
*/

static int		get_len(int value, int base)
{
	int		len;

	len = value <= 0 ? 2 : 1;
	while (ft_abs(value / base) > 0)
	{
		len++;
		value /= base;
	}
	len += ft_abs(value - (value / base)) > 0 ? 1 : 0;
	return (len);
}

static char		get_digit(int value, int base)
{
	char	*base_str;

	base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return (base_str[ft_abs(value - (value / base * base))]);
}

/*
** @brief      Convert inveger value to a null-terminated string that represents
**             it in the specified base.
**
**             Base is expressed as an integer, from 2 to 36. The characters
**             comprising the base are the digits from range [0-9] and
**             upper-case letters [A-Z].
**
**             If base is invalid, NULL is returned. No control for the overflow
**             or undeflow provided.
**
** @param      value  value to be converted
** @param      base   integer representation of the base
**
** @return     null-terminated string representation of the value provided
*/

char			*ft_itoa_base(int value, int base)
{
	int		i;
	int		len;
	char	*str;

	if (base < 2 || base > 36)
		return (NULL);
	len = get_len(value, base);
	if ((str = (char *)malloc(sizeof(char) * (len))) == NULL)
		return (NULL);
	len -= (str[len - 1] = '\0') == '\0' ? 1 : 0;
	i = 0;
	str[i++] = (char)(value < 0 ? '-' : i--);
	while (ft_abs(value / base) > 0)
	{
		str[len-- - 1] = get_digit(value, base);
		value /= base;
	}
	str[i] = get_digit(value, base);
	return (str);
}
