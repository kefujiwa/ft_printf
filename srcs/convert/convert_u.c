/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:53:00 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 17:18:56 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

int		convert_u(t_data *data)
{
	unsigned int	u;
	char			*s;

	u = (unsigned int)va_arg(data->ap, int);
	if (!(s = ft_itoa_base((long)u, 10)))
		return (0);
	if (data->precision == 0 && u == 0)
	{
		free(s);
		if (!(s = ft_strdup("")))
			return (0);
	}
	if (!fill_zero(&s, data->precision, ft_strlen(s)))
		return (0);
	if (data->precision >= 0)
		data->zero = 0;
	ft_putchar_unit(data, s, ft_strlen(s));
	free(s);
	return (1);
}
