/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 12:12:05 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/25 23:30:18 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Exit lem_in after freeing the memory and send and error message
**
** 1st parameter : Error reference
*/
#if 1
static const 		t_error g_error[] =
{
	{"Parsing error : not an integer"},
	{"Parsing error : first letter room name"},
};
#endif

void			ft_exit(int ref)
{
	ft_del_singl_anthill();
	ft_del_singl_shortest_path();
	EXIT_FAIL(g_error[--ref].message);
}
