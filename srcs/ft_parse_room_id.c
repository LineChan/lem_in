/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:50:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/03 16:47:11 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a room id
**
** 1st parameter : line to be checked
** 2nd parameter : coordinates
** 3rd parameter : parsing depth
** 4th parameter : option
*/

int					ft_parse_room_id(char *line,
										int coordinate[],
										int depth,
										int option[])
{
	int			len;

	option[0] ? ft_print_parsing(depth, "room_id", line) : 0;
	len = ft_parse_room_name(line, depth + 1, option);
	line += ++len;
	if (*line == '-')
		return (-1);
	if ((*line++ != ' ') || (*line == ' '))
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	coordinate[0] = ft_parse_nb(&line, depth + 1, option);
	if (*line++ != ' ' || (*line == ' '))
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	coordinate[1] = ft_parse_nb(&line, depth + 1, option);
	if (ft_strlen(line))
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	return (len);
}
