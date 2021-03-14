/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:57:47 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 18:36:44 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

/*
** EXTERNAL LIBRARIES
*/
# include <stdarg.h>
# include <stddef.h>

/*
** STRUCTURE
*/
typedef struct	s_data
{
	const char	*content;
	va_list		ap;
	size_t		i;
	long		width;
	long		precision;
	long		len;
	char		conversion;
	short		left;
	short		zero;
}				t_data;

#endif
