/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_read_and_save.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 00:11:15 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/29 18:17:28 by mvillemi         ###   ########.fr       */
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
	*line = ft_fgnt("test.txt", '\n');
	if (!*line)
		return (0);
	ft_fprintf(FD,"%s\n", *line);
	return (1);
}
