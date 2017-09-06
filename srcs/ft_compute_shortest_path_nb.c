/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_shortest_path_nb.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 13:55:44 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/06 13:12:31 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Compute the maximum number of shortest paths
*/
void			ft_compute_shortest_path_nb(void)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (i < ROOM_NB)
	{
			if (MATRIX[START_REF][i])
				++SP_NB;
		++i;
	}
	i ^= i;
	while (i < ROOM_NB)
	{
		if (MATRIX[END_REF][i])
			++count;
		++i;
	}
	SP_NB = MIN(SP_NB, count);
	//SP_NB = (SP_NB < 4) ? SP_NB : 3;
	//ft_fprintf(2, "compute shortest_path nb : %d\n", SP_NB);
}
