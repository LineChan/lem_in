/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 01:28:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/04 14:51:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	int			ret;

	FD = open("input.txt", O_CREAT | O_RDWR | O_TRUNC);
	if ((ret = ft_parse()))
		ft_exit(1);
	/*
	t_lst		*node;
	node = ft_find_room_with_ref(&ANTHILL, 2);
	ft_lst_moveto_prev(ANTHILL.prev, &SHORTEST_PATH);
	ft_printf("node : %s\n", R_NAME(node));
	*/
	ft_fprintf(2, "{RED:SEGFAULT} main\n");
	ft_compute_shortest_path_nb();
	ft_iddsf();
	ft_printf("ANTHILL : ");ft_print_room_list(&ANTHILL);
	ft_print_shortest_path_list();
	ft_printf("\nFD : %d, ROOM_NB : %d, ANT_NB : %D, TUBE_NB : %d, START_REF :%d,END_REF : %d, SP_NB : %d\n", FD, ROOM_NB, ANT_NB, TUBE_NB, START_REF, END_REF, SP_NB);
	close(FD);
	ft_del_everything();
	return (0);
}
