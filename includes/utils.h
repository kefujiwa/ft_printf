/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:20:33 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/13 18:12:33 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** SELF-MADE HEADER FILES
*/
# include "data.h"
# include "libft.h"

/*
** EXTERNAL LIBRARIES
*/
# include <limits.h>
# include <stdlib.h>

/*
** PROTOTYPE DECLARATION
*/
int		fill_zero(char **s, long precision, long len);
char	*ft_itoa_base(long n, unsigned int base);
void	ft_putchar_unit(t_data *data, char *str, size_t len);
int		is_conversion(char c);
char	*str_toupper(char *str);

#endif
