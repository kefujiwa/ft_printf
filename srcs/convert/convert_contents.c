/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_contents.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:47:01 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 17:14:06 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

int	convert_contents(t_data *data)
{
	if (data->conversion == 'c')
		return (convert_c(data));
	else if (data->conversion == 's')
		return (convert_s(data));
	else if (data->conversion == 'p')
		return (convert_p(data));
	else if (data->conversion == 'd' || data->conversion == 'i')
		return (convert_di(data));
	else if (data->conversion == 'u')
		return (convert_u(data));
	else if (data->conversion == 'x' || data->conversion == 'X')
		return (convert_x(data));
	else if (data->conversion == '%')
		convert_percent(data);
	else
		data->i--;
	return (1);
}
