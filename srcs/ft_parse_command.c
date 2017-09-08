/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 20:16:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/08 13:20:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if the line 
**
** 1st parameter : line to be checked
*/
static void		ft_parse_start_end(char *line, int depth)
{
	int		x;
	int		y;
	int		ret;

	ret = ft_parse_room_id(line, &x, &y, depth + 1);
	ft_add_room(line, ret, x, y);
	ft_parse_duplicate_name_and_coordinate(line, ret, x, y);
}

int				ft_parse_command(char **line , int depth, int *flag)
{
	ft_print_parsing(depth, "command", *line);
	if (!ft_strcmp((*line + 2), "start"))
	{
		ft_print_parsing((depth + 1), "START", "");
		if (COMMAND_START)
			ft_exit(9);
		*flag |= FLAG_START;
		ft_parse_new_line(line);
		ft_parse_start_end(*line, depth + 1);
		START_REF = R_REF(ANTHILL.prev);
		return (1);
	} 
	if (!ft_strcmp((*line + 2), "end"))
	{
		ft_print_parsing((depth + 1), "END", "");
		if (COMMAND_END)
			ft_exit(10);
		*flag |= FLAG_END;
		ft_parse_new_line(line);
		ft_parse_start_end(*line, depth + 1);
		END_REF = R_REF(ANTHILL.prev);
		return (1);
	}
	return (0);
}
