/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:54:24 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 18:10:41 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_data(t_data *data)
{
	data->len = 0;
	data->i = 0;
	data->width = 0;
	data->precision = 0;
	data->left = 0;
	data->zero = 0;
}

int			ft_printf(const char *fmt, ...)
{
	t_data	*data;

	if (!fmt || *fmt == '\0')
		return (0);
	if (!(data = (t_data *)ft_calloc(1, sizeof(t_data))))
		return (-1);
	init_data(data);
	data->content = fmt;
	va_start(data->ap, fmt);
	if (!parse_line(data))
		return (-1);
	va_end(data->ap);
	return (data->len);
}
