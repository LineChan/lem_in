/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:50:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 00:22:37 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a room id
*/
void			ft_parse_room_id(char **line)
{
	ft_printf("       {YELLOW:START} : ft_parse_room_id ---> '%s'\n", *line);
	ft_parse_room_name(line);
	ft_printf("       {YELLOW:START} : ft_parse_room_id ---> '%s'\n", *line);
}
