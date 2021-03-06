/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 01:28:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/17 15:32:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(int ac, char **av)
{
	char		*line;

	line = NULL;
	ft_parse(ac, av, &line);
	if (!ft_iddfs())
	{
		while ((line = ft_gnt(FD, '\n')))
			ft_fprintf(FD, "%s\n", line);
		ft_del_everything();
		return (0);
	}
	if (PATH_LEN(SHORTEST_PATH.next) == 1)
	{
		ft_quick_solution(&line);
		return (0);
	}
	DEBUG_MODE ? ft_print_shortest_path_list() : ft_print_input();
	ft_ant_repartition();
	close(FD);
	ft_del_everything();
	return (0);
}
