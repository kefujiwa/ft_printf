/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:31:33 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 17:22:30 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		fill_zero(char **s, long precision, long len)
{
	char	*zerop;
	long	i;
	long	diff;

	diff = precision - len;
	if (diff <= 0)
		return (1);
	if (!(zerop = (char *)ft_calloc(diff + 1, sizeof(char))))
		return (0);
	i = 0;
	while (i < diff)
	{
		zerop[i] = '0';
		i++;
	}
	*s = ft_strjoin(zerop, *s);
	free(zerop);
	return (1);
}
