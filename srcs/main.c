/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 01:28:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/02 01:06:18 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	int			ret;

	FD = open("input.txt", O_CREAT | O_RDWR | O_TRUNC);
	if ((ret = ft_parse()))
		ft_exit(1);
	ft_printf("\nFD : %d, ROOM_NB : %d, ANT_NB : %D, TUBE_NB : %d, START_REF :%d,END_REF : %d\n", FD, ROOM_NB, ANT_NB, TUBE_NB, START_REF, END_REF);
	/*
	t_lst		*node;
	node = ft_find_room_with_ref(&ANTHILL, 2);
	ft_lst_moveto_prev(ANTHILL.prev, &SHORTEST_PATH);
	ft_printf("node : %s\n", R_NAME(node));
	*/
	ft_IDDSF();
	ft_print_room_list(&ANTHILL);
	close(FD);
	ft_del_everything();
	return (0);
}
