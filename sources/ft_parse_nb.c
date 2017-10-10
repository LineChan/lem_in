/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:15:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/03 16:37:28 by mvillemi         ###   ########.fr       */
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
	int					sign;
	unsigned int		nb;

	nb = 0;
	sign = 1;
	option[0] ? ft_print_parsing(depth, "parse_nb", *cursor) : 0;
	if (**cursor == '-')
		sign *= -1;
	if ((**cursor == '-') || (**cursor == '+'))
		++*cursor;
	if (**cursor == ' ')
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	while (ft_isdigit(**cursor))
		nb = (nb << 3) + (nb << 1) + *(*cursor)++ - 48;
	if ((!ft_isspace(**cursor)) && (**cursor != 0 ||
				((nb > 2147483647) || ((nb > 2147483648) && IS_NEG(sign)))))
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	return (nb * sign);
}
