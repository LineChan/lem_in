/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_everything.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:43:21 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/30 17:44:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Free all allocated structures so the program can exit properly
*/
void			ft_del_everything(void)
{
	ft_del_matrix();
	ft_del_singl_anthill();
	ft_del_singl_shortest_path();
}
