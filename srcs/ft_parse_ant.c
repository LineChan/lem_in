/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 23:01:57 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/27 22:50:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if if the line is an ant
**
** 1st parameter : line to check
*/
void			ft_parse_ant(char **line)
{
	char		*cursor;

	ft_printf("{YELLOW:START} ft_parse_ant\n");
	*line = ft_fgnt("test.txt", '\n');
	ft_parse_new_line(line);
	/*
	while (!(ft_parse_new_line(line)))
	{
		*line = ft_fgnt("test.txt", '\n');
		if (!*line)
			ft_exit(5);
	}
	*/
	cursor = *line;
	if (IS_NEG((ANT_NB = ft_parse_nb(&cursor))))
		ft_exit(1);
	ft_printf("{YELLOW:line  } --->  '%s'\n", *line);
	*line += (*line) - cursor;
	if (ft_strlen(cursor))
		ft_exit(1);
	ft_printf("{YELLOW:cursor  } --->  '%s'\n", cursor);
	ft_parse_new_line(line);
	ft_printf("{YELLOW:END  } ft_parse_ant\n");
}
