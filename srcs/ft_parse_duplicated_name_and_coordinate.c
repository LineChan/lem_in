/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_coordinate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:35:12 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/29 11:58:33 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is no room at the same location
**
** 1st parameter : x value
** 2nd parameter : y value
*/
void			ft_parse_duplicate_name_and_coordinate(const char *line,
														const int ret,
														int coordinate[])
{
	t_lst		*it;

	it = ANTHILL.next;
	while (it != ANTHILL.prev)
	{
		if ((R_X(it) == coordinate[0]) && (R_Y(it) == coordinate[1]))
			ft_exit(14);
		if (!ft_strncmp(line, R_NAME(it), ret))
			ft_exit(15);
		it = it->next;
	}
}
