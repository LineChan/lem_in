/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:50:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 02:08:56 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a room id
*/
void			ft_parse_room_id(char **line)
{
	size_t		len;
	ft_printf("       {YELLOW:START} : ft_parse_room_id ---> '%s'\n", *line);
	len = ft_parse_room_name(line);
	*line += --len;
	if (!(*(++*line) == ' '))
		ft_exit(3);
	ft_parse_nb(line);
	ft_printf("       {YELLOW:START} : ft_parse_room_id ---> '%s'\n", *line);
}
