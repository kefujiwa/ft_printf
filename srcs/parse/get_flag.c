/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:42:09 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 17:07:52 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_flag(t_data *data)
{
	while (data->content[data->i])
	{
		if (data->content[data->i] == '-')
			data->left = 1;
		else if (data->content[data->i] == '0')
			data->zero = 1;
		else
			return ;
		data->i++;
	}
	return ;
}
