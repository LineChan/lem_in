/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singl_shortest_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:41:03 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/03 17:43:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** All shortest path related functions
*/

t_shortest_path			*shortest_path(void)
{
	static t_shortest_path		*ptr = 0;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_shortest_path))))
		INIT_LST_HEAD(ptr->result_head);
	return (ptr);
}

void					ft_del_singl_shortest_path(void)
{
	t_shortest_path				*ptr;

	ptr = shortest_path();
	ft_lst_foreach(&(ptr->result_head), &ft_del_shortest_path);
	ft_memdel((void **)&ptr);
}

void					ft_create_new_path(void)
{
	ft_add_shortest_path();
	ft_copy_end_room_to_path();
}

void					ft_add_shortest_path(void)
{
	static int		ref = 0;
	t_result		*new;

	if (!(new = ft_memalloc(sizeof(t_result))))
		EXIT_FAIL("Failed memory allocation");
	INIT_LST_HEAD(new->room_head);
	new->ref = ref++;
	ft_lst_add_prev(&new->lst, &SHORTEST_PATH);
}

void					ft_copy_end_room_to_path(void)
{
	t_room		*new;

	if (!(new = ft_memalloc(sizeof(t_room))))
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	new->name = ft_strndup(R_NAME(ANTHILL.prev), R_SIZE(ANTHILL.prev));
	ft_memcpy(new, C_ROOM(ANTHILL.prev), R_SIZE(ANTHILL.prev));
	ft_lst_add_prev(&new->lst, &PATH(SHORTEST_PATH.prev));
}
