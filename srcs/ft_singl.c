/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:10:13 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/30 15:41:51 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Singleton functions
*/
t_anthill		*anthill(void)
{
	static t_anthill	*ptr = 0;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_anthill))))
		INIT_LST_HEAD(ptr->room_head);
	return (ptr);
}

t_shortest_path		*shortest_path(void)
{
	static t_shortest_path	*ptr = 0;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_shortest_path))))
		INIT_LST_HEAD(ptr->result_head);
	return (ptr);
}
