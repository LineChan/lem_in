/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_coordinate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:35:12 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/06 16:51:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is no room at the same location
**
** 1st parameter : x value
** 2nd parameter : y value
*/
int				ft_parse_coordinate(const int x, const int y)
{
	t_lst		*it;

	it = ANTHILL.next;
	while (it != &ANTHILL)
	{
		if (!((R_X(it) != x)   &&    (R_Y(it) != y)))
            :x
		it = it->next;
	}
	return (1);
}
