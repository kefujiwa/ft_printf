/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:41:32 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 18:40:56 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_conversion(t_data *data)
{
	size_t	i;
	char	*str;

	i = 0;
	str = "ipdcsxXu%";
	while (str[i] != '\0')
	{
		if (data->content[data->i] == str[i])
			data->conversion = str[i];
		i++;
	}
}
