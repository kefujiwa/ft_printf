/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:50:55 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 18:44:42 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

static char	*trim_str(char *str, long pre_size)
{
	char	*p;
	int		i;

	if (!(p = (char *)ft_calloc(pre_size + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (pre_size != 0 && i < pre_size && str[i])
	{
		p[i] = str[i];
		i++;
	}
	return (p);
}

int			convert_s(t_data *data)
{
	char	*str;
	int		len;

	str = (char *)va_arg(data->ap, char *);
	if (str == NULL)
		if (!(str = trim_str("(null)", 6)))
			return (0);
	len = ft_strlen(str);
	if (data->precision >= 0 && data->precision < len)
	{
		if (!(str = trim_str(str, data->precision)))
			return (0);
		ft_putchar_unit(data, str, data->precision);
		free(str);
	}
	else
		ft_putchar_unit(data, str, len);
	return (1);
}
