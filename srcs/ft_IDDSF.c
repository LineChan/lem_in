/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_IDDSF.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 22:58:44 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/04 13:35:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**
*/
int				ft_explore_adjacent(int ref, int limit);
int				ft_DLS(int src_ref, int limit);

int				ft_explore_adjacent(int ref, int limit)
{
	int		i;
	int		j;
	//t_lst	*node_tmp;

	i = 0;
	while (i < ROOM_NB)
	{
		if (MATRIX[ref][i] == 1)
		{
			if (ft_DLS(i, limit - 1))
			{
				ft_fprintf(2, "{YELLOW:PATH} : %d\n", i);
				if (i != END_REF)
				{
					ft_lst_moveto_prev(ft_find_room_with_ref(&ANTHILL, i),
									&C_RESULT(SHORTEST_PATH.prev)->room_head);
					j = 0;
					while (j < ROOM_NB)
					{
						ft_set_matrix(i,j,0);
						++j;
					}
				}
				else
					ft_add_shortest_path();
				return (1);
			}
		}
		++i;
	}
	return (0);
}

int				ft_DLS(int src_ref, int limit)
{
	int		i;

	ft_fprintf(2,"src_ref : %d\n", src_ref);
	i = 0;
	if (src_ref == END_REF)
	{
		ft_fprintf(2, "found a path !\n");
		return (1);
	}
	if (limit <= 0)
	{
		ft_fprintf(2, "{RED:DEAD END}\n");
		ft_reset_matrix();
		return (0);
	}
	i = 0;
	while (i < ROOM_NB)
	{
		MATRIX[i][src_ref] = 0;
		++i;
	}
	if (ft_explore_adjacent(src_ref, limit))
		return (1);
	return  (0);
}

void			ft_IDDSF(void)
{
	int		limit;
	int		sp_nb;

	limit = 0;
	SP_NB = 5;
	sp_nb = SP_NB;
	while (sp_nb > 0)
	{
		while (limit < ROOM_NB)
		{
			if (ft_DLS(START_REF, limit))
			{
				ft_print_matrix();
				ft_printf("{GREEN:PATH FOUND}\n");
				break ;
			}
			++limit;
		}
		--sp_nb;
	}
}
#if 0
	ft_printf("{GREEN:shortest path list}\n");ft_print_shortest_path_list();
	ft_lst_moveto_prev(ANTHILL.next, &C_RESULT(SHORTEST_PATH.prev)->room_head);
	ft_print_room_list(&C_RESULT(SHORTEST_PATH.prev)->room_head);
	ft_add_shortest_path();
	ft_printf("{GREEN:shortest path list}\n");ft_print_shortest_path_list();
	ft_lst_moveto_prev(ANTHILL.next, &C_RESULT(SHORTEST_PATH.prev)->room_head);
	ft_print_room_list(&C_RESULT(SHORTEST_PATH.prev)->room_head);
	ft_printf("{RED:END}\n");
#endif
