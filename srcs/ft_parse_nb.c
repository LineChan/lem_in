/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:15:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/29 00:34:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a number
**
** 1st parameter : cursor to be checked
** 2nd parameter : parsing depth
** 3rd parameter : option
*/

int				ft_parse_nb(char **cursor, int depth, int option[])
{
	unsigned int		nb;
	int					sign;

	nb = 0;
	sign = 1;
	option[0] ? ft_print_parsing(depth, "parse_nb", *cursor) : 0;
	if (**cursor == '-')
		sign *= -1;
	if ((**cursor == '-') || (**cursor == '+'))
		++*cursor;
	if (**cursor == ' ')
		ft_exit(7);
	while (ft_isdigit(**cursor))
		nb = (nb << 3) + (nb << 1) + *(*cursor)++ - 48;
	if (!ft_isspace(**cursor))
	{
		if (**cursor != 0 ||
				((nb > 2147483647) || ((nb > 2147483648) && (sign == -1))))
			ft_exit(7);
	}
	return (nb * sign);
}
