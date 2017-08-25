/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:15:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/25 18:56:33 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a number
*/
int				ft_parse_nb(char **line)
{
	unsigned int		nb;
	int					sign;

	nb = 0;
	sign = 1;
	ft_printf("          {YELLOW:START  } : ft_parse_nb ---> %s\n", *line);
	if (**line == '-' && ft_isdigit(*(++*line)))
		sign *= -1;
	if (**line == '+')
		++*line;
	while (**line != ' ' && ft_isdigit(*(*line)))
	{
		nb = nb * 10 + **line - 48;
		if (((nb > INT_MAX) && !IS_NEG(sign))
				|| (((nb - 1) > INT_MAX) && IS_NEG(sign)))
			ft_exit(1);
		++*line;
	}
	ft_printf("          {YELLOW:END    } : ft_parse_nb ---> %s {GREEN:OK}\n", *line);
	return (nb * sign);
}
