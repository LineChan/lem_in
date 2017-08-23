/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_shortest_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 19:40:57 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/23 15:01:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Free all the rooms on a given path
**
** 1st parameter : shortest path to be removed
*/
void		ft_del_shortest_path(t_lst *path)
{
#if 0
	ft_printf("del shortest  : %d\n", C_RESULT(path)->ref);
	ft_printf("single ? %d\n", ft_lst_is_single(&C_RESULT(path)->room_head));
	ft_printf("1st room : %s\n", C_ROOM(C_RESULT(path)->room_head.next)->name);
	ft_printf("1st room : %s\n", C_ROOM(C_RESULT(path)->room_head.next)->name);
	ft_printf("single ? %d\n", ft_lst_is_single(&C_RESULT(path)->room_head));
#endif
	if (!ft_lst_is_head(&C_RESULT(path)->room_head))
	{
		//ft_lst_foreach(&C_RESULT(path)->room_head, &ft_del_room);
	}
	ft_printf("{RED:SEGFAULT}");
	//ft_lst_del(path);
	//ft_memdel((void **)C_RESULT(path));
}
