/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 01:28:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/23 17:00:25 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	ft_printf("ROOM_NB : %d\tANT_NB : %d\tTUBE_NB : %d\tSTART : %d\tEND : %d SHORTEST_PATH : %d\n", ROOM_NB, ANT_NB, TUBE_NB, START, END, SP_NB);
	ROOM_NB = 10;
	ANT_NB = 4;
	TUBE_NB = 15;
	START = 0;
	END = 9;
	SP_NB = 4;
	ft_printf("ROOM_NB : %d\tANT_NB : %d\tTUBE_NB : %d\tSTART : %d\tEND : %d SHORTEST_PATH : %d\n", ROOM_NB, ANT_NB, TUBE_NB, START, END, SP_NB);
#if 1
	ft_add_room("1st room");
	ft_add_room("2nd room");

#if 0
	ft_add_shortest_path();
	ft_lst_moveto_prev(ANTHILL.next, &C_RESULT(SHORTEST_PATH.next)->room_head);
	ft_printf("shortest path ref : %d\n", C_RESULT(SHORTEST_PATH.next)->ref);
	ft_del_shortest_path(SHORTEST_PATH.next);
#endif

	ft_printf("AHTILL.next : %s\n", C_ROOM(ANTHILL.next)->name);
	ft_printf("AHTILL.next->next : %s\n\n\n", C_ROOM(ANTHILL.next->next)->name);
	t_lst		*it;
	it = ANTHILL.next;
	ft_printf("it : %s\n", R_NAME(it));
	ft_del_room(it);
	ft_printf("AHTILL.next : %s\n", C_ROOM(ANTHILL.next)->name);
	ft_del_room(ANTHILL.next);
#if 0
	t_lst		*it;
	it = C_RESULT(SHORTEST_PATH.next)->room_head.next;
	ft_printf("name : %s\n", C_ROOM(it)->name);
	ft_del_shortest_path(
#endif
#endif
	//ft_del_singl_anthill();
	//ft_del_singl_shortest_path();
	return (0);
}
#if 0

	ft_printf("shortest path ref : %d\n", C_RESULT(SHORTEST_PATH.next)->ref);
	ft_lst_moveto_prev(ANTHILL.next, &C_RESULT(SHORTEST_PATH.next)->room_head);
	it = C_RESULT(SHORTEST_PATH.next)->room_head.next;
	ft_printf("name : %s\n", C_ROOM(it)->name);
#endif
