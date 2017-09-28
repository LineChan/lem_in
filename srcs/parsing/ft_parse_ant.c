/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 23:01:57 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/28 12:39:50 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if if the line is an ant number
**
** 1st parameter : line to read from the input
** 2nd parameter : parsing depth
** 3rd parameter : parsing visualization option
*/
void			ft_parse_ant(char **line, int depth)
{
	//ft_parse_new_line(line);
	*line = ft_gnt(0, '\n');
	ft_print_parsing(depth, "parse_ant", *line);
	if (0 > (ANT_NB = ft_parse_nb(line, depth + 1)))
		ft_exit(1);
	if (ft_strlen(*line) || !ANT_NB)
		ft_exit(1);
	ft_printf("%d\n", ANT_NB);
}
