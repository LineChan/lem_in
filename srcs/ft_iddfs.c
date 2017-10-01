/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_IDDSF.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 22:58:44 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/29 18:56:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Find all the shortest paths
*/
static int				ft_explore_adjacent(const int ref, const int limit);
static int				ft_dls(const int src_ref, const int limit);

static int				ft_explore_adjacent(const int ref, const int limit)
{
	int		i;
	int		j;

	i = 0;
	while (i < ROOM_NB)
	{
		if ((MATRIX[ref][i] == 1) && (ft_dls(i, limit - 1)))
		{
			if (i != END_REF)
			{
				ft_lst_moveto_next(ft_find_room_with_ref(&ANTHILL, i),
					&PATH(SHORTEST_PATH.prev));
				j = 0;
				while (j < ROOM_NB)
					ft_set_matrix(i, j++, 0);
			}
			else
			{
				ft_add_shortest_path();
				ft_copy_end_room_to_path();
			}
			++PATH_LEN(SHORTEST_PATH.prev);
			return (1);
		}
		++i;
	}
	return (0);
}

static int				ft_dls(const int src_ref, const int limit)
{
	int		i;

	if (src_ref == END_REF)
		return (1);
	if (limit <= 0)
	{
		ft_reset_matrix();
		return (0);
	}
	i = 0;
	while (i < ROOM_NB)
	{
		if (!(MATRIX[i][src_ref] ^ 1))
			MATRIX[i][src_ref] = -1;
		++i;
	}
	if (ft_explore_adjacent(src_ref, limit))
		return (1);
	return  (0);
}

int				ft_iddfs(void)
{
	int		limit;

	limit = 0;
	while (SP_NB > 0)
	{
		while (limit < ROOM_NB)
		{
			if (ft_dls(START_REF, limit))
				break ;
			++limit;
		}
		--SP_NB;
	}
	if (ft_lst_is_head(&SHORTEST_PATH))
		return (0);
	return (1);
}
