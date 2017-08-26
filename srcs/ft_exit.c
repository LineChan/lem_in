/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 12:12:05 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 22:35:11 by mvillemi         ###   ########.fr       */
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
	{"Parsing error : ant entry"},
	{"Parsing error : first letter room name"},
	{"Parsing error : no space"},
	{"Parsing error : not an ant"},
};
#endif

void			ft_exit(int ref)
{
	ft_del_singl_anthill();
	ft_del_singl_shortest_path();
	EXIT_FAIL(g_error[--ref].message);
}
