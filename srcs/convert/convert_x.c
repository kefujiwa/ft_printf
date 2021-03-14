/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:53:54 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 17:19:50 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

int		convert_x(t_data *data)
{
	unsigned int	u;
	char			*s;

	u = (unsigned int)va_arg(data->ap, int);
	if (!(s = ft_itoa_base((long)u, 16)))
		return (0);
	if (data->conversion == 'X')
		s = str_toupper(s);
	if (!fill_zero(&s, data->precision, ft_strlen(s)))
		return (0);
	if (data->precision == 0 && u == 0)
	{
		free(s);
		s = ft_strdup("");
	}
	if (data->precision >= 0)
		data->zero = 0;
	ft_putchar_unit(data, s, ft_strlen(s));
	free(s);
	return (1);
}
