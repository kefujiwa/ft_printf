/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:47:54 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 17:16:07 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

static	int	check_precision(t_data *data, char **s, int di)
{
	if (data->precision == 0 && di == 0)
	{
		if (!(*s = ft_strdup("")))
			return (0);
	}
	if (data->zero && data->precision < 0 && !data->left)
	{
		if (!fill_zero(s, data->width - 1, ft_strlen(*s)))
			return (0);
	}
	else
	{
		if (!fill_zero(s, data->precision, ft_strlen(*s)))
			return (0);
	}
	return (1);
}

static	int	check_negative(char **s, int neg)
{
	char	*tmp;

	if (neg)
	{
		tmp = *s;
		if (!(*s = ft_strjoin("-", *s)))
		{
			free(tmp);
			return (0);
		}
		free(tmp);
	}
	return (1);
}

int			convert_di(t_data *data)
{
	long	di;
	char	*s;
	int		neg;

	neg = 0;
	di = (long)va_arg(data->ap, int);
	if (di < 0)
	{
		neg = 1;
		di = di * -1;
	}
	if (!(s = ft_itoa_base(di, 10)))
		return (0);
	if (!(check_precision(data, &s, di)))
		return (0);
	if (!(check_negative(&s, neg)))
		return (0);
	if (data->precision >= 0)
		data->zero = 0;
	ft_putchar_unit(data, s, ft_strlen(s));
	free(s);
	return (1);
}
