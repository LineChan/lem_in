/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 20:16:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/17 15:03:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a command
**
** 1st parameter : input line
** 2nd parameter : parsing depth
** 3rd parameter : ##start ##end rooms flag
*/

static void		ft_parse_start_end(char *line, int depth)
{
	int		coordinate[2];
	int		ret;

	if (IS_NEG((ret = ft_parse_room_id(line, coordinate, depth + 1))))
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	ft_add_room(line, ret, coordinate);
	ft_parse_duplicate_name_and_coordinate(line, ret, coordinate);
}

static int		ft_parse_start(char **line,
									int depth,
									int *flag)
{
	DEBUG_MODE ? ft_print_parsing(depth, "start", "") : 0;
	if (COMMAND_START)
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	*flag |= FLAG_START;
	ft_parse_new_line(line);
	ft_parse_start_end(*line, depth);
	START_REF = R_REF(ANTHILL.prev);
	return (1);
}

static int		ft_parse_end(char **line,
								int depth,
								int *flag)
{
	DEBUG_MODE ? ft_print_parsing((depth), "end", "") : 0;
	if (COMMAND_END)
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	*flag |= FLAG_END;
	ft_parse_new_line(line);
	ft_parse_start_end(*line, depth);
	END_REF = R_REF(ANTHILL.prev);
	return (1);
}

int				ft_parse_command(char **line,
									int depth,
									int *flag)
{
	DEBUG_MODE ? ft_print_parsing(depth, "command", *line) : 0;
	if (!ft_strcmp((*line + 2), "start"))
		return (ft_parse_start(line, depth + 1, flag));
	if (!ft_strcmp((*line + 2), "end"))
		return (ft_parse_end(line, depth + 1, flag));
	return (0);
}
