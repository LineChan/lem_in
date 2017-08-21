/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_singl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:05:38 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/21 18:08:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_del_singl(void)
{
	t_anthill	*ptr;

	ptr = ft_singleton();
	ft_list_foreach(ptr->list, &ft_del_room);
	ft_memdel((void **)&ptr);
}
