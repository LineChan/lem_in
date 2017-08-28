/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:50:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/28 18:42:20 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a room id
**
** 1st parameter : line to be checked
*/
size_t				ft_parse_room_id(char *cursor,
										int *x,
										int *y,
										int depth)
{
	size_t		len;

	ft_print_parsing(depth, "room_id", cursor);
	len = ft_parse_room_name(cursor, depth + 1);
	cursor += ++len;
	if (*cursor++ != ' ' || (*cursor == ' ')) 
		ft_exit(3);
	*x = ft_parse_nb(&cursor, depth + 1);
	if (*cursor++ != ' ' || (*cursor == ' ')) 
		ft_exit(3);
	*y = ft_parse_nb(&cursor, depth + 1);
	return (len);
}
