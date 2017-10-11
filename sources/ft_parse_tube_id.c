/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tube_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:08:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/11 02:04:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check is the line is a tube id
**
** 1st parameter : input line
** 2nd parameter : rooms' references
** 3rd parameter : parsing depth
*/

int				ft_parse_tube_id(char *line,
								int ref[],
								int depth)
{
	int			len;
	t_lst		*node_tmp;

	DEBUG_MODE ? ft_print_parsing(depth, "tube_id", line) : 0;
	len = 0;
	while (*(line + len) && (*(line + len) != '-'))
		++len;
	if (!(node_tmp = ft_find_room_with_name(&ANTHILL, line, len)))
		return (0);
	ref[0] = R_REF(node_tmp);
	line += ++len;
	len ^= len;
	while (*(line + len))
		++len;
	if (!(node_tmp = ft_find_room_with_name(&ANTHILL, line, len)))
		return (0);
	ref[1] = R_REF(node_tmp);
	return (1);
}
