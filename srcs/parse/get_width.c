/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:43:30 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 18:41:22 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	skip_irrelevant_char(t_data *data)
{
	while (data->content[data->i] && !is_conversion(data->content[data->i])
		&& data->content[data->i] != '.' && data->content[data->i] != '*')
	{
		data->i++;
	}
}

static void	parse_wildcard(t_data *data)
{
	long wildcard;

	while (data->content[data->i] == ' ')
		data->i++;
	if (data->content[data->i] == '*')
	{
		wildcard = (long)va_arg(data->ap, int);
		if (wildcard < 0)
		{
			wildcard *= -1;
			data->left = 1;
		}
		data->width = wildcard;
		data->i++;
	}
}

void		get_width(t_data *data)
{
	parse_wildcard(data);
	while (ft_isdigit(data->content[data->i]))
	{
		data->width *= 10;
		data->width += (data->content[data->i] - '0');
		data->i++;
	}
	parse_wildcard(data);
	skip_irrelevant_char(data);
}
