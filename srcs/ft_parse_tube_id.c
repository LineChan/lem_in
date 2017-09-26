/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tube_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:08:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/26 18:29:30 by mvillemi         ###   ########.fr       */
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
								int depth)
{
	int			len;
	t_lst		*node_tmp;

	ft_print_parsing(depth, "tube_id", line);
	len = 0;
	while (*(line + len) && (*(line + len) != '-'))
		++len;
	if (!(node_tmp = ft_find_room_with_name(&ANTHILL, line, len)))
		return (0);
	*ref_1 = R_REF(node_tmp);
	line += ++len;
	len ^= len;
	while (*(line + len - 1))
		++len;
	if (!(node_tmp = ft_find_room_with_name(&ANTHILL, line, len)))
		return (0);
	*ref_2 = R_REF(node_tmp);
	return (1);
}
