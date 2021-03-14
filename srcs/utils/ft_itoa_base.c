/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:30:40 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 17:23:53 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static	int		ft_intlen(long n, unsigned int base)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n >= base)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static	void	ft_convert(long n, unsigned int base, char *p, long len)
{
	if (n < 0)
	{
		p[0] = '-';
		n *= -1;
	}
	else if (n == 0)
	{
		p[0] = '0';
	}
	while (n > 0)
	{
		if (n % base <= 9)
			p[len] = (n % base) + 48;
		else if (n % base <= 15)
			p[len] = (n % base) + 87;
		n = n / base;
		len--;
	}
}

char			*ft_itoa_base(long n, unsigned int base)
{
	char	*p;
	long	len;

	if (base == 0)
		return (0);
	len = ft_intlen(n, base);
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (NULL);
	len--;
	if (n < 0 && base == 10)
		p[0] = '-';
	if (n == LLONG_MIN)
	{
		if (base == 10)
			ft_strlcpy(p, "-9223372036854775808", 21);
		else
			ft_strlcpy(p, "8000000000000000", 16);
	}
	ft_convert(n, base, p, len);
	return (p);
}
