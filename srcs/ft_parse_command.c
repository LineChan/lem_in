/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 20:16:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/03 16:31:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a command
**
** 1st parameter : input line
** 2nd parameter : parsing depth
** 3rd parameter : ##start ##end rooms flag
** 4th parameter : option
*/

static void		ft_parse_start_end(char *line, int depth, int option[])
{
	int		coordinate[2];
	int		ret;

	ret = ft_parse_room_id(line, coordinate, depth + 1, option);
	ft_add_room(line, ret, coordinate);
	ft_parse_duplicate_name_and_coordinate(line, ret, coordinate);
}

static int		ft_parse_start(char **line,
									int depth,
									int *flag,
									int option[])
{
	option[0] ? ft_print_parsing(depth, "start", "") : 0;
	if (COMMAND_START)
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	*flag |= FLAG_START;
	ft_parse_new_line(line);
	ft_parse_start_end(*line, depth, option);
	START_REF = R_REF(ANTHILL.prev);
	return (1);
}

static int		ft_parse_end(char **line,
								int depth,
								int *flag,
								int option[])
{
	option[0] ? ft_print_parsing((depth), "end", "") : 0;
	if (COMMAND_END)
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	*flag |= FLAG_END;
	ft_parse_new_line(line);
	ft_parse_start_end(*line, depth, option);
	END_REF = R_REF(ANTHILL.prev);
	return (1);
}

int				ft_parse_command(char **line,
									int depth,
									int *flag,
									int option[])
{
	option[0] ? ft_print_parsing(depth, "command", *line) : 0;
	if (!ft_strcmp((*line + 2), "start"))
		return (ft_parse_start(line, depth + 1, flag, option));
	if (!ft_strcmp((*line + 2), "end"))
		return (ft_parse_end(line, depth + 1, flag, option));
	return (0);
}
