/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 12:12:05 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/28 23:38:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Exit lem_in after freeing the memory and send and error message
**
** 1st parameter : Error reference
*/
static const 		t_error g_error[] =
{
#if 1
	{"Parsing error : ant entry"},
	{"Parsing error : first letter room name"},
	{"Parsing error : spacing"},
	{"Parsing error : not an ant"},
	{"Parsing error : end of file"},
	{"Parsing error : rooms' list"},
	{"Parsing error : not an int"},
	{"Parsing error : no tube list"},
	{"Parsing error : duplicated start room"},
	{"Parsing error : duplicated end room"},
	{"Failed memory allocation"},
	{"Error : END or START room not connected"},
	{"No solution"},
	{"Parsing error : duplicated coordinates"},
	{"Parsing error : duplicated room names"},
#endif
	{"error"},
	{"error"},
	{"error"},
	{"error"},
	{"error"},
	{"error"},
	{"error"},
	{"error"},
	{"error"},
	{"error"},
	{"error"},
	{"error"},
	{"error"},
	{"error"},
	{"error"},
};

void			ft_exit(int ref)
{
	ft_del_everything();
	EXIT_FAIL(g_error[--ref].message);
}
