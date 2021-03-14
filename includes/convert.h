/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:12:34 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 18:16:22 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

/*
** SELF-MADE HEADER FILES
*/
# include "data.h"
# include "libft.h"
# include "utils.h"

/*
** EXTERNAL LIBRARIES
*/
# include <stdarg.h>
# include <stdlib.h>

/*
** PROTOTYPE DECLARATION
*/
int		convert_c(t_data *data);
int		convert_contents(t_data *data);
int		convert_di(t_data *data);
int		convert_p(t_data *data);
void	convert_percent(t_data *data);
int		convert_s(t_data *data);
int		convert_u(t_data *data);
int		convert_x(t_data *data);

#endif
