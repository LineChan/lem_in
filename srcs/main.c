/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 01:28:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/20 20:27:33 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
#if 1
	ft_printf("ROOM_NB : %d\tANT_NB : %d\tTUBE_NB : %d\tSTART : %d\tEND : %d\n", ROOM_NB, ANT_NB, TUBE_NB, START, END );
	ROOM_NB = 10;
	ANT_NB = 4;
	TUBE_NB = 15;
	START = 0;
	END = 9;
	ft_printf("ROOM_NB : %d\tANT_NB : %d\tTUBE_NB : %d\tSTART : %d\tEND : %d\n", ROOM_NB, ANT_NB, TUBE_NB, START, END);
#if 0
	ft_add_room("1st room");
	ft_add_room("2nd room");
	node it;
	it = ANTHILL.next;
	while (it != &ANTHILL)
	{
		ft_printf("room's name : %s\n", R_NAME(it));
		it = it->next;
	}
#endif
	return (0);
}
