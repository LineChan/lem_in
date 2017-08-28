/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:50:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/28 14:14:09 by mvillemi         ###   ########.fr       */
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
									int *y)
{
	size_t		len;

	ft_printf("----{YELLOW:START} ft_parse_room_id --> '%s'\n", cursor);
	len = ft_parse_room_name(cursor);
	cursor += ++len;
	if (*cursor++ != ' ' || (*cursor == ' ')) 
		ft_exit(3);
	*x = ft_parse_nb(&cursor);
	if (*cursor++ != ' ' || (*cursor == ' ')) 
		ft_exit(3);
	*y = ft_parse_nb(&cursor);
	ft_printf("----{YELLOW:END  } ft_parse_room_id --> '%s' {GREEN:OK}\n", cursor);
	return (len);
}
