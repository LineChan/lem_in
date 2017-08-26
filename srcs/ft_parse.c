/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:16:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 20:16:26 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Parse stdin, return 1 if the input is correct
*/
int				ft_parse(void)
{
	char	*line;

	ft_parse_ant(&line);
	ft_parse_room_list(&line);
	return (0);
}
