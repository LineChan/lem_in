/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:39:30 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/01 16:36:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Delete a room
**
** 1st paremeter : room's node to be removed
*/
void			ft_del_room(t_lst *src)
{
	t_room		*ptr;

	ptr = C_ROOM(src);
	if (!ptr)
		return ;
	ft_memdel((void **)&(ptr->name));
	ft_lst_del(src);
	ft_memdel((void **)&ptr);
}
