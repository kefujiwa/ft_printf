/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:38:55 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 18:17:28 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	reset_data(t_data *data)
{
	data->conversion = '\0';
	data->precision = -1;
	data->width = 0;
	data->zero = 0;
	data->left = 0;
}

static void	parse_data(t_data *data)
{
	get_flag(data);
	get_width(data);
	get_precision(data);
	get_conversion(data);
}

int			parse_line(t_data *data)
{
	if (!ft_strncmp(data->content, "%", ft_strlen(data->content)))
		return (0);
	while (data->content[data->i])
	{
		if (data->content[data->i] == '%')
		{
			data->i++;
			reset_data(data);
			parse_data(data);
			if (!convert_contents(data))
				return (0);
		}
		else
		{
			ft_putchar_fd(data->content[data->i], 1);
			data->len++;
		}
		data->i++;
	}
	return (1);
}
