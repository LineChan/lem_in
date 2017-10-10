/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:39:30 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/01 21:23:21 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Delete functions
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

void			ft_del_everything(void)
{
	ft_del_matrix();
	ft_del_singl_anthill();
	ft_del_singl_shortest_path();
}

void			ft_del_shortest_path(t_lst *path)
{
	t_result	*ptr;

	ptr = C_RESULT(path);
	if (!ft_lst_is_head(path))
		ft_lst_foreach(&(ptr->room_head), &ft_del_room);
	ft_lst_del(path);
	ft_memdel((void **)&ptr);
}
