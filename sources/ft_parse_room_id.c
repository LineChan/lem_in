/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:50:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/17 13:42:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a room id
**
** 1st parameter : line to be checked
** 2nd parameter : coordinates
** 3rd parameter : parsing depth
*/

int					ft_parse_room_id(char *line,
										int coordinate[],
										int depth)
{
	int			len;

	DEBUG_MODE ? ft_print_parsing(depth, "room_id", line) : 0;
	len = ft_parse_room_name(line, depth + 1);
	line += ++len;
	if (*line == '-')
		return (-1);
	if ((*line++ != ' ') || (*line == ' '))
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	coordinate[0] = ft_parse_nb(&line, depth + 1);
	if (*line++ != ' ' || (*line == ' '))
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	coordinate[1] = ft_parse_nb(&line, depth + 1);
	if (ft_strlen(line))
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	return (len);
}
