/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant_repartition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:20:16 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/29 10:31:35 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Compute ants' repartation on shortest paths
*/
void			ft_move_ant(t_lst *head, int *finish)
{
	t_lst		*it_b;
	t_lst		*it_a;

	it_b = head->prev;
	it_a = it_b->prev;
	if (R_ANT(it_b) != 0)
		++*finish;
	while (it_a != head)
	{
		if (R_ANT(it_a) || R_ANT(it_b))
		{
			R_ANT(it_b) = R_ANT(it_a);
			R_ANT(it_a) ^= R_ANT(it_a);
		}
		it_b = it_b->prev;
		it_a = it_a->prev;
	}
}

void			ft_send_ant(t_lst *head, int *ant_ref)
{
	t_lst		*it;

	it = head->next;
	R_ANT(it) = *ant_ref;
	++*ant_ref;
}

void			ft_ant_repartition()
{
	int			current_ant;
	int			finish;
	int			move;
	t_lst		*it;

	current_ant = 1;
	finish = 0;
	move = 0;
	while (finish != ANT_NB)
	{
		it = SHORTEST_PATH.next;
		while (it != &SHORTEST_PATH)
		{
			ft_move_ant(&C_RESULT(it)->room_head, &finish);
			if (current_ant <= ANT_NB)
			{
				if (current_ant != ANT_NB)
				{
					if ((PATH_LEN(it) <= ((ANT_NB - current_ant) * PATH_LEN(SHORTEST_PATH.next))) || (PATH_REF(it) == 0))
						ft_send_ant(&C_RESULT(it)->room_head, &current_ant);
				}
				else if ((PATH_LEN(it) <= PATH_LEN(SHORTEST_PATH.next)) || (PATH_REF(it) == 0))
					ft_send_ant(&C_RESULT(it)->room_head, &current_ant);
			}
			it = it->next;
		}
		++move;
		ft_print_output();
	}
}
