/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_read_and_save.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 00:11:15 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/08 13:27:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Read the input and save it in a temporary file
**
** 1st parameter : line to be processed
*/
int				ft_parse_gnt_and_save(char **line)
{
	*line = ft_gnt(0 , '\n');
	if (!*line)
		return (0);
	ft_fprintf(FD,"%s\n", *line);
	if ((**line == '#') && (*(*line + 1) != '#'))
		ft_parse_gnt_and_save(line);
	if (*(*line) == '#' && (*(*line + 1) == '#'))
	{
		if (!ft_strcmp((*line + 2), "start") || !ft_strcmp((*line + 2), "end"))
			return (0);
		ft_parse_gnt_and_save(line);
	}
	return (1);
}
