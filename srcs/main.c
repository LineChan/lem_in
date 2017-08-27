/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 01:28:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/28 00:04:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	int			ret;
	t_lst		*it;

	if ((ret = ft_parse()))
		ft_exit(1);

#if 0
	while ((line = ft_fgnt("test.txt", '\n')))
	{
		if (!(ft_parse(line)))
		{
			ft_del_singl_anthill();
			return (0);
		}
	}
#endif
	it = &ANTHILL;
	ft_printf("ANT_NB : %d\n", ANT_NB);
	it = it->next;
	ft_printf("R_NAME() : %s X: %d Y: %d\n", R_NAME(it), R_X(it), R_Y(it));
	it = it->next;
	ft_printf("R_NAME() : %s X: %d Y: %d\n", R_NAME(it), R_X(it), R_Y(it));
	ft_printf("ROOM_NB : %d\n", ROOM_NB);
	ft_del_singl_anthill();
	ft_del_singl_shortest_path();
	return (0);
}

/*
	ft_printf("ROOM_NB : %d\tANT_NB : %d\tTUBE_NB : %d\tSTART : %d\tEND : %d SHORTEST_PATH : %d\n", ROOM_NB, ANT_NB, TUBE_NB, START, END, SP_NB);
	ROOM_NB = 10;
	ANT_NB = 4;
	TUBE_NB = 15;
	START = 0;
	END = 9;
	SP_NB = 4;
	ft_printf("ROOM_NB : %d\tANT_NB : %d\tTUBE_NB : %d\tSTART : %d\tEND : %d SHORTEST_PATH : %d\n", ROOM_NB, ANT_NB, TUBE_NB, START, END, SP_NB);
	ft_add_room("1st room");
	ft_add_room("2nd room");
	ft_add_room("3rd room");

	ft_add_shortest_path();
	ft_add_shortest_path();
	ft_add_shortest_path();
	ft_add_shortest_path();
#if 1
	ft_lst_moveto_prev(ANTHILL.next->next, &C_RESULT(SHORTEST_PATH.next)->room_head);
	ft_lst_moveto_prev(ANTHILL.next, &C_RESULT(SHORTEST_PATH.next->next)->room_head);
	ft_printf("shortest path ref : %d\n", C_RESULT(SHORTEST_PATH.next)->ref);
#endif
#if 0
	ft_printf("\nAHTILL.next : %s\n", C_ROOM(ANTHILL.next)->name);
	ft_printf("AHTILL.next->next : %s\n\n", C_ROOM(ANTHILL.next->next)->name);
	ft_del_room(ANTHILL.next);
	ft_printf("AHTILL.next : %s\n", C_ROOM(ANTHILL.next)->name);
#endif
*/
