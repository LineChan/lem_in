/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:45:05 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/02 00:53:35 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Add a room to the list
**
** 1st parameter : room's name
** 2nd parameter : room's name size
** 3rd parameter : coordinate
*/
void			ft_add_room(const char *name,
							const size_t size,
							int coordinate[])
{
	static int	ref = 0;
	t_room		*new;

	if (!(new = ft_memalloc(sizeof(t_room))))
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	INIT_LST_HEAD(new->lst);
	++ROOM_NB;
	new->name = ft_strndup(name, size);
	new->name_size = size;
	new->ref = ref++;
	new->x = coordinate[0];
	new->y = coordinate[1];
	ft_lst_add_prev(&new->lst, &ANTHILL);
}
