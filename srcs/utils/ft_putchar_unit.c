/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_unit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:37:16 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 18:42:13 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_putstr(char *str, long len)
{
	long	i;

	i = 0;
	while (i < len)
		write(1, &str[i++], 1);
}

void		ft_putchar_unit(t_data *data, char *str, size_t len)
{
	long	diff;

	if (!str)
		return ;
	diff = data->width - len;
	if (diff < 0)
	{
		ft_putstr(str, len);
		data->len += len;
		return ;
	}
	data->len += data->width;
	if (data->left == 1)
	{
		ft_putstr(str, len);
		while (diff--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (diff--)
			ft_putchar_fd(data->zero ? '0' : ' ', 1);
		ft_putstr(str, len);
	}
	return ;
}
