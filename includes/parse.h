/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:01:11 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 18:17:54 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/*
** SELF-MADE HEADER FILES
*/
# include "convert.h"
# include "data.h"
# include "libft.h"
# include "utils.h"

/*
** EXTERNAL LIBRARIES
*/
# include <stdarg.h>

/*
** PROTOTYPE DECLARATION
*/
int		parse_line(t_data *data);
void	get_conversion(t_data *data);
void	get_flag(t_data *data);
void	get_precision(t_data *data);
void	get_width(t_data *data);

#endif
