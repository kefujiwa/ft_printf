/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:49:28 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 16:49:52 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_p(t_data *data)
{
	long	p;
	char	*s;

	p = (long)va_arg(data->ap, void *);
	s = ft_itoa_base(p, 16);
	if (data->precision == 0 && p == 0)
	{
		free(s);
		if (!(s = ft_strdup("")))
			return (0);
	}
	if (!fill_zero(&s, data->precision, ft_strlen(s)))
		return (0);
	if (!(s = ft_strjoin("0x", s)))
		return (0);
	if (data->precision >= 0)
		data->zero = 0;
	ft_putchar_unit(data, s, ft_strlen(s));
	free(s);
	return (1);
}
