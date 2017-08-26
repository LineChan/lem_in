/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 21:03:25 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 22:32:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if it is a room's name
**
** 1st parameter : line to be checked
*/
int				ft_parse_room_name(char *line)
{
	ft_printf("--------{YELLOW:START} ft_parse_room_name --> '%s'  \n", line);
	if (!ft_parse_first_letter(line))
	{
		ft_printf("--------{YELLOW:END  } ft_parse_room_name --> '%s'  {RED:KO}\n", line);
		return (0);
	}
	ft_printf("--------{YELLOW:END  } ft_parse_room_name --> '%s'  {GREEN:OK}\n", line);
		getchar();
	return (ft_parse_letter(++line) + 1);
}
