/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant_repartition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:20:16 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/03 18:03:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define SHORTEST_PATH_LEN (PATH_LEN(SHORTEST_PATH.next))

/*
** Compute ants' repartition on shortest paths
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

void			ft_ant_repartition(void)
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
			ft_move_ant(&PATH(it), &finish);
			if (current_ant <= ANT_NB)
				if ((((current_ant != ANT_NB) &&
				((PATH_LEN(it) <= ((ANT_NB - current_ant) * SHORTEST_PATH_LEN))
				|| !PATH_REF(it)))) || ((PATH_LEN(it) <= SHORTEST_PATH_LEN)))
					ft_send_ant(&PATH(it), &current_ant);
			it = it->next;
		}
		++move;
		ft_print_output();
	}
}
