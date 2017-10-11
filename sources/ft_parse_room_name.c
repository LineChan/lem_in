/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 21:03:25 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/11 02:32:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if it is a room's name
**
** 1st parameter : input line
** 2nd parameter : parsing depth
*/

int				ft_parse_room_name(char *line, int depth)
{
	DEBUG_MODE ? ft_print_parsing(depth, "room_name", "") : 0;
	ft_parse_first_letter(line, depth + 1);
	return (ft_parse_letter(++line, depth + 1));
}
