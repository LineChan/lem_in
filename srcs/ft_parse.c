/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:16:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/02 00:09:11 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Parsing ants' number, rooms' list and tubes' list
**
** 1st parameter : input line
** 2nd parameter : option
*/
void				ft_parse(int ac,
								char **av,
								char **line,
								int option[])
{
	int		depth;

	ft_handle_option(ac, av, option);
	FD = *option ? open("input.txt", O_CREAT | O_RDWR | O_TRUNC, 0666) : 1;
	depth = 0;
	ft_parse_ant(line, depth + 1, option);
	*line = ft_gnt(0, '\n');
	if (!*line)
		ft_parse_new_line(line);
	depth ^= depth;
	ft_parse_room_list(line, depth + 1, option);
	depth ^= depth;
	ft_parse_tube_list(line, depth + 1, option);
	while ((*line = ft_gnt(0, '\n')))
		ft_fprintf(FD, "%s\n", *line);
	ft_clear_unlinked_room();
	ft_lst_moveto_prev(ft_find_room_with_ref(&ANTHILL, END_REF), &ANTHILL);
	ft_compute_shortest_path_nb();
	if (option[1])
		SP_NB = (option[1] > SP_NB) ? SP_NB : option[1];
}
