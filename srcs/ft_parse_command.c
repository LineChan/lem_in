/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 20:16:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/29 11:35:09 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if the line 
**
** 1st parameter : line to be checked
*/
static void		ft_parse_start_end(char *line, int depth, int option[])
{
	int		coordinate[2];
	int		ret;

	ret = ft_parse_room_id(line, coordinate, depth + 1, option);
	ft_add_room(line, ret, coordinate);
	ft_parse_duplicate_name_and_coordinate(line, ret, coordinate);
}

int				ft_parse_command(char **line , int depth, int *flag, int option[])
{
	option[0] ? ft_print_parsing(depth, "command", *line) : 0;
	if (!ft_strcmp((*line + 2), "start"))
	{
		option[0] ? ft_print_parsing((depth + 1), "start", "") : 0;
		if (COMMAND_START)
			ft_exit(9);
		*flag |= FLAG_START;
		ft_parse_new_line(line);
		ft_parse_start_end(*line, depth + 1, option);
		START_REF = R_REF(ANTHILL.prev);
		return (1);
	} 
	if (!ft_strcmp((*line + 2), "end"))
	{
		option[0] ? ft_print_parsing((depth + 1), "end", "") : 0;
		if (COMMAND_END)
			ft_exit(10);
		*flag |= FLAG_END;
		ft_parse_new_line(line);
		ft_parse_start_end(*line, depth + 1, option);
		END_REF = R_REF(ANTHILL.prev);
		return (1);
	}
	return (0);
}
