/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:39:30 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 01:01:45 by mvillemi         ###   ########.fr       */
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
	ft_printf("       {GREEN:start del_room}\n");
	if (ft_lst_is_head(src))
	{
		ft_printf("      No room to del\n   {GREEN:end del_room}\n");
		return ;
	}
	//ft_printf("      R_NAME(src) : %s\n", C_ROOM(src)->name);
	ft_memdel((void **)&(ptr->name));
	ft_lst_del(src);
	ft_memdel((void **)&ptr);
	ft_printf("      {GREEN:end del_room}\n");
}
