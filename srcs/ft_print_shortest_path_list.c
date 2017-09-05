/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_shortest_path_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 10:52:50 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/05 21:40:38 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Print the shortest paths' list
*/
void		ft_print_shortest_path_list(void)
{
	t_lst		*it;

	it = SHORTEST_PATH.next;
	while (it != &SHORTEST_PATH)
	{
		ft_fprintf(2, "[ {YELLOW:%d} ] %-5d", PATH_REF(it), PATH_LEN(it)); 
		ft_print_room_list(&C_RESULT(it)->room_head);
		it = it->next;
		write(2, "\n", 1);
	}
}
