/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_first_letter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 21:07:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/28 18:47:54 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a first letter
**
** 1st parameter : line to be checked
*/
void				ft_parse_first_letter(char *line, int depth)
{
	ft_print_parsing(depth, "first_letter", "");
	if (!((ft_isascii(*line)) && (*line != 'L')
				&& (*line != '#') && *line))
		ft_exit(6);
}
