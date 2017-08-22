/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 01:28:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 20:20:02 by mvillemi         ###   ########.fr       */
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
	//ft_add_shortest_path();
	t_lst *it;
	it = ANTHILL.next;
	while (it != &ANTHILL)
	{
		ft_printf("room's name : %s\n", R_NAME(it));
		it = it->next;
	}
	it = ANTHILL.next;
	while (it != &ANTHILL)
	{
		ft_printf("room's name : %s\n", R_NAME(it));
		it = it->next;
	}
#endif
	ft_del_singl_anthill();
	ft_del_singl_shortest_path();
	return (0);
}
