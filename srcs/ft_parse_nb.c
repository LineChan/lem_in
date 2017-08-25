/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:15:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/25 17:57:02 by mvillemi         ###   ########.fr       */
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
	ft_printf("sign : %d\n", sign);
#if 0
	if (*line == '+')
		++line;
	while (*line != ' ' || line)
	{
		nb = nb * 10 + *line - 48;
		++line;
	}
#endif
	ft_printf("          {YELLOW:END    } : ft_parse_nb ---> %s {GREEN:OK}\n", *line);
	getchar();
	return (nb * sign);
}
