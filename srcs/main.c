/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 01:28:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/24 21:20:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(int ac, char **av)
{
	int			ret;
	int			sp;
	char		*line;

	FD = open("input.txt", O_CREAT | O_RDWR | O_TRUNC);
	if ((ret = ft_parse()))
		ft_exit(1);
	sp = 0;
	if (ac > 1)
	{
		--ac;
		++av;
		if (!ft_strcmp("--shortest_path", *av))
		{
			if (ac ==  1)
			   EXIT_FAIL("Error : how many shortest path ?");
			sp = ft_atoi(*(++av));
		}
	}
	ft_lst_moveto_prev(ft_find_room_with_ref(&ANTHILL, END_REF), &ANTHILL);
	ft_compute_shortest_path_nb();
	if (sp)
		SP_NB = (sp > SP_NB) ? SP_NB : sp;
	if (!ft_iddsf())
	{
		while ((line = ft_fgnt("input.txt", '\n')))
			ft_printf("%s\n", line);
		return (0);
	}
	ft_lst_foreach(&ANTHILL, &ft_del_room);
	if (PATH_LEN(SHORTEST_PATH.next) == 1)
	{
		while ((line = ft_fgnt("input.txt", '\n')))
			ft_printf("%s\n", line);
		ret = 0;
		ft_print_output();
		while (ret < ANT_NB)
			ft_printf("L%d-%s ", ++ret, R_NAME(ft_find_room_with_ref(&C_RESULT(SHORTEST_PATH.next)->room_head, END_REF)));
		write(1, "\n", 1);
		return (0);
	}
	while ((line = ft_fgnt("input.txt", '\n')))
		ft_printf("%s\n", line);
	ft_ant_repartition();
	close(FD);
	ft_del_everything();
	return (0);
}
#if 0
	ft_fprintf(2, "\nFD : %d, ROOM_NB : %d, ANT_NB : %D, TUBE_NB : %d, START_REF :%d,END_REF : %d, SP_NB : %d\n", FD, ROOM_NB, ANT_NB, TUBE_NB, START_REF, END_REF, SP_NB);
#endif
