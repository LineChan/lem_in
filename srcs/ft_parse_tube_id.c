/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tube_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:08:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/29 01:17:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
** Check is the line is a tube id
**
** 1st parameter : line to be checked
*/
int				ft_parse_tube_id(char *line,
								int *ref_1,
								int *ref_2,
								int depth,
								int option[])
{
	int			len;
	t_lst		*node_tmp;

	option[0] ? ft_print_parsing(depth, "tube_id", line) : 0;
	len = 0;
	while (*(line + len) && (*(line + len) != '-'))
		++len;
	if (!(node_tmp = ft_find_room_with_name(&ANTHILL, line, len)))
		return (0);
	*ref_1 = R_REF(node_tmp);
	line += ++len;
	len ^= len;
	while (*(line + len))
		++len;
	if (!(node_tmp = ft_find_room_with_name(&ANTHILL, line, len)))
		return (0);
	*ref_2 = R_REF(node_tmp);
	return (1);
}
