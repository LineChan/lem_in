/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_shortest_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 19:40:57 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/23 18:17:28 by mvillemi         ###   ########.fr       */
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
	t_result	*ptr;

	ft_printf("  {YELLOW:start del_path}\n");
	ft_printf("    PATH_REF : %d\n", PATH_REF(path));
	ptr = C_RESULT(path);
	if (!ft_lst_is_head(path))
		ft_lst_foreach(&(ptr->room_head), &ft_del_room);
	ft_lst_del(path);
	ft_memdel((void **)&ptr);
	ft_printf("  {YELLOW:end del_path}\n");
}
