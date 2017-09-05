/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant_repartition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:20:16 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/05 15:00:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Compute ants' repartation on shortest paths
*/
void			ft_move_ant(t_lst *head, int *ant_ref, const int path_len)
{
	t_lst		*it_b;
	t_lst		*it_a;

	it_b = head->prev;
	it_a = it_b->prev;
	ft_fprintf(2, "path_len %d\n", path_len);
	while (it_a != head)
	{
		ft_fprintf(2, " -%s-    -%s-\n", R_NAME(it_a), R_NAME(it_b));
		if (R_ANT(it_a))
		{
			R_ANT(it_b) = R_ANT(it_a);
		}
		it_b = it_b->prev;
		it_a = it_a->prev;
	}
	++*ant_ref;

}

void			ft_ant_repartition()
{
	t_lst		*it;
	int			ant_ref;

	ant_ref = 1;
	while (ant_ref <= ANT_NB)
	{
		it = SHORTEST_PATH.next;
		while (it != &SHORTEST_PATH)
		{
			ft_fprintf(2, "  [ {YELLOW:%d} ]\n", PATH_REF(it));
			ft_move_ant(&C_RESULT(it)->room_head, &ant_ref, PATH_LEN(it));
			//ft_printf("L%d-%s", ant_ref++, R_NAME(C_RESULT(SHORTEST_PATH.next)->room_head.next));
			it = it->next;
		}
		write(1, "\n", 1);
	}
}
