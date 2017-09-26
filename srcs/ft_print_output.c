/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:13:54 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/26 18:51:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Print well formated output
*/
static void			ft_print_room_output(t_lst *head)
{
	t_lst		*it;

	it = head->prev;
	while (it != head)
	{
		if (R_ANT(it))
			ft_printf("L%d-%s ", R_ANT(it), R_NAME(it));
		it = it->prev;
	}
}

void				ft_print_output(void)
{
	t_lst		*it;

	it = SHORTEST_PATH.next;
	while (it != &SHORTEST_PATH)
	{
		ft_print_room_output(&C_RESULT(it)->room_head);
		it = it->next;
	}
	write(1, "\n", 1);
}
