/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_shortest_path_nb.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:56:03 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/26 18:18:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Compute how many shortest paths are going to be processed
**
** 1st parameter : number of arguments
** 2nd parameter : list of arguments
*/

static void			ft_compute_shortest_path_nb(void)
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
}

void			ft_handle_shortest_path_nb(int ac, char **av)
{
	int		sp;

	sp = 0;
	if (ac > 1)
	{
		--ac;
		++av;
		if (!ft_strcmp("--shortest_path", *av))
		{
			if (ac == 1)
				EXIT_FAIL("error : how many shortest path ?");
			sp = ft_atoi(*(++av));
		}
	}
	ft_lst_moveto_prev(ft_find_room_with_ref(&ANTHILL, END_REF), &ANTHILL);
	ft_compute_shortest_path_nb();
	if (sp)
		SP_NB = (sp > SP_NB) ? SP_NB : sp;
}
