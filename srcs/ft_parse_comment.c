/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 20:16:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/28 18:36:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if the line 
**
** 1st parameter : line to be checked
*/
int				ft_parse_comment(char *line, int depth)
{
	ft_print_parsing(depth, "comment", line);
	return (0);
}
