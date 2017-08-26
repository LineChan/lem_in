/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:50:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 17:31:40 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a room id
*/
int					ft_parse_room_id(char **line)
{
	size_t		len;

	ft_printf("       {YELLOW:START} : ft_parse_room_id ---> '%s'\n", *line);
	len = ft_parse_room_name(line);
	if (IS_NEG(len))
		return (3);
	*line += len;

	getchar();

	if (!((*(*line)++) == ' '))
		return (3);
	ft_parse_nb(line);

	if (!((*(*line)++) == ' '))
		return (3);
	ft_parse_nb(line);
	if (ft_strlen(*line))
		return (3);
	ft_printf("       {YELLOW:START} : ft_parse_room_id ---> '%s'\n", *line);
	return (0);
}
