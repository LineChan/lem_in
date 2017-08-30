/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:45:05 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/30 15:41:53 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Add a room to the list
*/
void			ft_add_room(const char *name,
							const size_t size,
							const int x,
							const int y)
{
	static int	ref = 0;
	t_room		*new;

	if (!(new = ft_memalloc(sizeof(t_room))))
		EXIT_FAIL("Failed memory allocation");
	INIT_LST_HEAD(new->lst);
	++ROOM_NB;
	new->name = ft_strndup(name, size);
	new->name_size = size;
	new->ref = ref++;
	new->x = x;
	new->y = y;
	ft_lst_add_prev(&new->lst, &(anthill()->room_head));
}
