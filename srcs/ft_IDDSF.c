/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_IDDSF.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 22:58:44 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/05 14:59:50 by mvillemi         ###   ########.fr       */
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
			ft_fprintf(2, "{YELLOW:PATH} : %d\n", i);
			if (i != END_REF)
			{
				ft_lst_moveto_next(ft_find_room_with_ref(&ANTHILL, i),
					&C_RESULT(SHORTEST_PATH.prev)->room_head);
				j = 0;
				while (j < ROOM_NB)
				{
					ft_set_matrix(i, j, 0);
					++j;
				}
			}
			else
			{
				ft_add_shortest_path();
				if (SP_NB == 1)
					ft_lst_moveto_prev(ANTHILL.prev,
									&C_RESULT(SHORTEST_PATH.prev)->room_head);
				else
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

	ft_fprintf(2, "src_ref : %d\n", src_ref);
	if (src_ref == END_REF)
		return (1);
	if (limit <= 0)
	{
		ft_reset_matrix();
		write(2, "\n", 1);
		ft_print_matrix();
		ft_fprintf(2, "{RED:DEAD END}\n");
		return (0);
	}
	i = 0;
	while (i < ROOM_NB)
	{
		if (MATRIX[i][src_ref] == 1)
			MATRIX[i][src_ref] = -1;
		++i;
	}
	if (ft_explore_adjacent(src_ref, limit))
		return (1);
	return  (0);
}

void			ft_iddsf(void)
{
	int		limit;

	limit = 0;
	while (SP_NB > 0)
	{
		while (limit < TUBE_NB)
		{
			if (ft_dls(START_REF, limit))
			{
				ft_printf("{GREEN:PATH FOUND}\n");
				break ;
			}
			++limit;
		}
		--SP_NB;
	}
	if (ft_lst_is_head(&SHORTEST_PATH))
		ft_printf("{RED:No Solution}\n");
}
