/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:46:18 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 18:43:10 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

int	convert_c(t_data *data)
{
	char	c;

	c = (char)va_arg(data->ap, int);
	if (!c)
		c = '\0';
	ft_putchar_unit(data, &c, 1);
	return (1);
}
