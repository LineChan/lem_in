/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:15:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 14:17:12 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a number
**
** 1st parameter : line to be checked
*/
int				ft_parse_nb(char **line)
{
	unsigned int		nb;
	int					sign;

	nb = 0;
	sign = 1;
	ft_printf("          {YELLOW:START  } : ft_parse_nb ---> '%s'\n", *line);
	if (**line == '-')
		sign *= -1;
	if ((**line == '-') || (**line == '+'))
		++*line;
	if (!ft_isdigit(**line))
		ft_exit(1);
	while (ft_isdigit(**line))
		nb = (nb << 3) + (nb << 1) + *(*line)++ - 48;
	if (!ft_isspace(**line))
	{
		if (**line != 0 ||
				((nb > 2147483647) || ((nb > 2147483648) && (sign == -1))))
			ft_exit(1);
	}
	ft_printf("          {YELLOW:END    } : ft_parse_nb ---> '%d'\n", nb * sign);
	return ((int)nb * sign);
}
/*
while (ft_isdigit(**s))
	nb = (nb << 3) + (nb << 1) + *(*s)++ - 48;
if (!ft_isspace(**s))
{
	if (**s != 0 ||
			((nb > 2147483647) || ((nb > 2147483648) && (sign == -1))))
		EXIT_FAIL("Error (not an integer)");
}
return ((int)nb * sign);

ft_printf("          {YELLOW:END    } : ft_parse_nb ---> '%d' {GREEN:OK}\n", nb * sign);
return ((int)nb * sign);
*/
