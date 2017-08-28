/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 23:01:57 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/29 01:09:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if if the line is an ant
**
** 1st parameter : line to check
*/
void			ft_parse_ant(char **line, int depth)
{
	char		*cursor;

	ft_print_parsing(depth, "parse_ant", *line);
	ft_parse_new_line(line);
	ft_parse_gnt_and_save(line);
	cursor = *line;
	if (IS_NEG((ANT_NB = ft_parse_nb(&cursor, depth + 1))))
		ft_exit(1);
	*line += (*line) - cursor;
	if (ft_strlen(cursor))
		ft_exit(1);
	ft_parse_new_line(line);
}
