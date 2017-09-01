/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_IDDSF.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 22:58:44 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/02 01:08:23 by mvillemi         ###   ########.fr       */
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
	//t_lst	*node;

	i = 0;
	ft_printf("ft_explore adjacent\n");
	while (i < ROOM_NB)
	{
		if (MATRIX[ref][i] == 1)
		{
			if (ft_DLS(i, limit - 1))
			{
				ft_printf("{YELLOW:PATH} : %d\n", i);
				//node = ft_find_room_with_ref(&ANTHILL, i);
				return (1);
			}
		}
		++i;
	}
	return (0);
}

int				ft_DLS(int src_ref, int limit)
{
	ft_printf("src_ref : %d\n", src_ref);
	if (src_ref == END_REF)
	{
		ft_printf("found a path !\n");
		return (1);
	}
	if (limit <= 0)
	{
		ft_printf("there is no path!\n");
		return (0);
	}
	if (ft_explore_adjacent(src_ref, limit))
		return (1);
	return  (0);
}

void			ft_IDDSF(void)
{
	int		limit;

	limit = 0;
	SP_NB = 1;
	ft_add_shortest_path();
	while ((limit < ROOM_NB) && SP_NB)
	{
		if (ft_DLS(START_REF, limit))
			--SP_NB;
		++limit;
	}
}
#if 0
	ft_lst_moveto_prev(ANTHILL.next->next, &C_RESULT(SHORTEST_PATH.next)->room_head);
		ft_lst_moveto_prev(ANTHILL.next, &C_RESULT(SHORTEST_PATH.next->next)->room_head);
			ft_printf("shortest path ref : %d\n", C_RESULT(SHORTEST_PATH.next)->ref);
#endif
