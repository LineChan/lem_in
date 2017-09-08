/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_new_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 23:12:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/08 15:40:44 by mvillemi         ###   ########.fr       */
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
	if (line && *line)
		ft_fprintf(FD, "%s\n", *line);
	*line = ft_gnt(0,'\n');
	if (!*line)
		return (-1);
	if ((**line == '#') && (*(*line + 1) != '#'))
		ft_parse_new_line(line);
	if (*(*line) == '#' && (*(*line + 1) == '#'))
	{
		if (!ft_strcmp((*line + 2), "start") || !ft_strcmp((*line + 2), "end"))
			return (0);
		ft_parse_new_line(line);
	}
	return (1);
}
