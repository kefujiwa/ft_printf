/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:56:16 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 18:11:44 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** SELF-MADE HEADER FILES
*/
# include "convert.h"
# include "data.h"
# include "libft.h"
# include "parse.h"
# include "utils.h"

/*
** EXTERNAL LIBRARIES
*/
# include <stdarg.h>

/*
** PROTOTYPE DECLARATION
*/
int		ft_printf(const char *fmt, ...);

#endif
