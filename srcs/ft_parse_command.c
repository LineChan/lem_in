/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 20:16:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/29 18:17:26 by mvillemi         ###   ########.fr       */
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
}

void			ft_parse_command(char **line, int depth)
{
	static int			exist_already = 0;

	ft_print_parsing(depth, "command", *line);
	if (!ft_strcmp((*line + 2), "START"))
	{
		ft_print_parsing((depth + 1), "START", "");
		if (COMMAND_START)
			ft_exit(9);
		exist_already |= FLAG_START;
		ft_parse_new_line(line);
		ft_parse_start_end(*line, depth + 1);
		START_REF = R_REF(ANTHILL.prev);
	} 
	if (!ft_strcmp((*line + 2), "END"))
	{
		ft_print_parsing((depth + 1), "END", "");
		if (COMMAND_END)
			ft_exit(10);
		exist_already |= FLAG_END;
		ft_parse_new_line(line);
		ft_parse_start_end(*line, depth + 1);
		END_REF = R_REF(ANTHILL.prev);
	}
}
