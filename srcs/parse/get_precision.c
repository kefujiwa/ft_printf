/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:42:50 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 18:42:46 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	skip_irrelevant_char(t_data *data)
{
	while (data->content[data->i] && !is_conversion(data->content[data->i]))
		data->i++;
	return ;
}

void		get_precision(t_data *data)
{
	int	period;

	period = 0;
	while (data->content[data->i] == '.')
	{
		data->precision = 0;
		data->i++;
		period = 1;
	}
	if (data->content[data->i] == '*' && period)
	{
		data->precision = (long)va_arg(data->ap, int);
		data->i++;
	}
	while (ft_isdigit(data->content[data->i]) && period)
	{
		data->precision *= 10;
		data->precision += (data->content[data->i] - '0');
		data->i++;
	}
	skip_irrelevant_char(data);
	return ;
}
