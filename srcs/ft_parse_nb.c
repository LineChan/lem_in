/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:15:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/27 23:55:31 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a number
**
** 1st parameter : cursor to be checked
*/
int				ft_parse_nb(char **cursor)
{
	unsigned int		nb;
	int					sign;

	nb = 0;
	sign = 1;
	ft_printf("--------{YELLOW:START} ft_parse_nb --> '%s'\n", *cursor);
	if (**cursor == '-')
		sign *= -1;
	if ((**cursor == '-') || (**cursor == '+'))
		++*cursor;
	while (ft_isdigit(**cursor))
		nb = (nb << 3) + (nb << 1) + *(*cursor)++ - 48;

	if (!ft_isspace(**cursor))
	{
		if (**cursor != 0 ||
				((nb > 2147483647) || ((nb > 2147483648) && (sign == -1))))
			ft_exit(7);
	}
	ft_printf("--------{YELLOW:END  } ft_parse_nb --> '%d'\n", nb * sign);
	return (nb * sign);
}
