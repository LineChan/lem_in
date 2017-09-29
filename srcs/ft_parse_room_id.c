/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:50:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/29 12:00:34 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a room id
**
** 1st parameter : line to be checked
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
		ft_exit(3);
	coordinate[0] = ft_parse_nb(&line, depth + 1, option);
	if (*line++ != ' ' || (*line == ' ')) 
		ft_exit(3);
	coordinate[1] = ft_parse_nb(&line, depth + 1, option);
	if (ft_strlen(line))
		ft_exit(6);
	return (len);
}
