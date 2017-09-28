/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 01:28:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/28 13:18:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Main function of lem-in
*/

int			main(int ac, char **av)
{
	int			ret;
	int			option[2];
	char		*line;

	ft_handle_option(ac, av, option);
	ft_printf("option [%d, %d]\n", option[0], option[1]);
	if ((ret = ft_parse()))
		ft_exit(1);
	ft_handle_shortest_path_nb(ac, av);
	if (!ft_iddsf())
	{
		while ((line = ft_gnt(0, '\n')))
			ft_printf("%s\n", line);
		ft_del_everything();
		return (0);
	}
	ft_lst_foreach(&ANTHILL, &ft_del_room);
	while ((line = ft_gnt(0, '\n')))
		ft_printf("%s\n", line);
	if (PATH_LEN(SHORTEST_PATH.next) == 1)
		ft_send_quick_solution();
	else
		ft_ant_repartition();
	ft_del_everything();
	return (0);
}
