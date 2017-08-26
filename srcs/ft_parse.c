/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:16:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 17:14:28 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Parse stdin, return 1 if the input is correct
*/
int				ft_parse(void)
{
	char	*line;

	ft_printf("{YELLOW:START : ft_parse {GREEN:OK}\n");
	if (ft_parse_ant(&line))
		ft_exit(4);
	ft_printf("IN BETWEEN : '%s'\n", line);
	ft_parse_room_list(&line);
	ft_printf("{YELLOW:END   : ft_parse {GREEN:OK}\n");
	return (0);
}
