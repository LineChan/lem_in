/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:15:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/06 16:11:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a number
**
** 1st parameter : cursor to be checked
*/
int				ft_parse_nb(char **cursor, int depth)
{
	unsigned int		nb;
	int					sign;

	nb = 0;
	sign = 1;
	ft_print_parsing(depth, "parse_nb", *cursor);
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
