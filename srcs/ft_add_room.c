/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:45:05 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/23 00:41:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Add a room to the list
*/
void			ft_add_room(const char *name)
{
	static int	ref = 0;
	t_room		*new;

	if (!(new = ft_memalloc(sizeof(t_room))))
		EXIT_FAIL("Failed memory allocation");
	INIT_LST_HEAD(new->lst);
	new->name = ft_strdup(name);
	new->ref = ref++;
	ft_lst_add_prev(&new->lst, &(anthill()->room_head));
}
