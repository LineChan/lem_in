/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_new_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 23:12:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/30 12:32:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if the line is a new line
**
** 1st paremter : line to be check
*/
int				ft_parse_new_line(char **line)
{
	while (ft_parse_gnt_and_save(line))
	{
		if (ft_strlen(*line))
			return (0);
	}
	return (1);
}
