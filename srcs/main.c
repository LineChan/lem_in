/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 01:28:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/05 14:29:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	int			ret;

	FD = open("input.txt", O_CREAT | O_RDWR | O_TRUNC);
	if ((ret = ft_parse()))
		ft_exit(1);
	ft_print_room_list(&ANTHILL);
	ft_lst_moveto_prev(ft_find_room_with_ref(&ANTHILL, END_REF), &ANTHILL);
	ft_print_room_list(&ANTHILL);
	ft_compute_shortest_path_nb();
	ft_iddsf();
	ft_lst_foreach(&ANTHILL, &ft_del_room);
	ft_printf("\nFD : %d, ROOM_NB : %d, ANT_NB : %D, TUBE_NB : %d, START_REF :%d,END_REF : %d, SP_NB : %d\n", FD, ROOM_NB, ANT_NB, TUBE_NB, START_REF, END_REF, SP_NB);
	ft_ant_repartition();
	ft_print_shortest_path_list();
	close(FD);
	ft_del_everything();
	return (0);
}
