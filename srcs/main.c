/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 01:28:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/29 17:01:26 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(int ac, char **av)
{
	int			ret;
	int			option[2];
	char		*line;

	line = NULL;
	ft_handle_option(ac, av, option);
	FD = *option ? open("input.txt", O_CREAT | O_RDWR | O_TRUNC, 0666) : 1;
	ft_parse(&line, option);
	ft_lst_moveto_prev(ft_find_room_with_ref(&ANTHILL, END_REF), &ANTHILL);
	ft_compute_shortest_path_nb();
	if (option[1])
		SP_NB = (option[1] > SP_NB) ? SP_NB : option[1];
	if (!ft_iddfs())
	{
		while ((line = ft_gnt(FD, '\n')))
			ft_fprintf(FD, "%s\n", line);
		return (0);
	}
	ft_lst_foreach(&ANTHILL, &ft_del_room);
	if (PATH_LEN(SHORTEST_PATH.next) == 1)
	{
		while ((line = ft_gnt(FD, '\n')))
			ft_fprintf(FD, "%s\n", line);
		ft_print_output();
		ret = 0;
		while (ret < ANT_NB)
			ft_fprintf(FD, "L%d-%s ", ++ret, R_NAME(ft_find_room_with_ref(&C_RESULT(SHORTEST_PATH.next)->room_head, END_REF)));
		write(1, "\n", 1);
		return (0);
	}
	while ((line = ft_fgnt("input.txt", '\n')) && option[0])
		ft_printf("%s\n", line);
	*option ? ft_print_shortest_path_list() : 0;
	ft_ant_repartition();
	close(FD);
	ft_del_everything();
	return (0);
}
