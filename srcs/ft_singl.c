/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:10:13 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 11:31:32 by mvillemi         ###   ########.fr       */
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
		INIT_LST_HEAD(ptr->lst_head);
	return (ptr);
}
