/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:16:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/29 10:17:40 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Parsing ants' number, rooms' list and tubes' list
**
** 1st parameter : input line
** 2nd parameter : option
*/
void				ft_parse(char **line, int option[])
{
	int		depth;

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
}
