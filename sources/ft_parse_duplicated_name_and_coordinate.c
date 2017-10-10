/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_coordinate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:35:12 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/03 17:23:32 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is no room at the same location
**
** 1st parameter : input line
** 2nd parameter : name's size
** 3rd parameter : coordinate
*/

void			ft_parse_duplicate_name_and_coordinate(const char *line,
														const int size,
														int coordinate[])
{
	t_lst		*it;

	it = ANTHILL.next;
	while (it != ANTHILL.prev)
	{
		if (((R_X(it) == coordinate[0]) && (R_Y(it) == coordinate[1])) ||
				(!ft_strncmp(line, R_NAME(it), size)))
		{
			ft_del_everything();
			EXIT_FAIL("ERROR");
		}
		it = it->next;
	}
}
