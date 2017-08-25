/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:16:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/25 23:26:37 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Parse stdin, return 1 if the input is correct
**
** 1st parameter : line to parse
*/
int				ft_parse(void)
{
	char	*line;

	ft_printf("{YELLOW:START : ft_parse {GREEN:OK}\n");
	ft_parse_ant(&line);
	ft_printf("IN BETWEEN : '%s'\n", line);
	ft_parse_room_list(&line);
	/*
	int		nb;

	nb = 0;
	if (!nb)
	{
		ft_del_singl_anthill();
		EXIT_FAIL("ft_parse : nb == 0");
	}
	*/
	ft_printf("{YELLOW:END   : ft_parse {GREEN:OK}\n");
	return (0);
}
