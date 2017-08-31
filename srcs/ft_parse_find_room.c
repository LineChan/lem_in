/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_find_room.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:37:06 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/31 13:50:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Find a room according to its name
**
** 1st parameter : room name to find
** 2nd parameter : name length
** 3rd parameter : function to compare rooms' name
*/
t_lst			*ft_parse_find_room(const char *room_name,
									const int len)
{
	t_lst                *it;

	if (ft_lst_is_head(&ANTHILL))
		return (0);
	it = ANTHILL.next;
	while (it != &ANTHILL)
	{
		if (!ft_strncmp(room_name, R_NAME(it), len))
			return (it);
		it = it->next;
	}
	return (0);
}
