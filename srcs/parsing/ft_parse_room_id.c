/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:50:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/06 16:11:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a room id
**
** 1st parameter : line to be checked
*/
int					ft_parse_room_id(char *line,
										int *x,
										int *y,
										int depth)
{
	int			len;

	ft_print_parsing(depth, "room_id", line);
	len = ft_parse_room_name(line, depth + 1);
	line += ++len;
	if (*line == '-')
		return (-1);
	if ((*line++ != ' ') || (*line == ' ')) 
		ft_exit(3);
	*x = ft_parse_nb(&line, depth + 1);
	if (*line++ != ' ' || (*line == ' ')) 
		ft_exit(3);
	*y = ft_parse_nb(&line, depth + 1);
	if (ft_strlen(line))
		ft_exit(6);
	return (len);
}
