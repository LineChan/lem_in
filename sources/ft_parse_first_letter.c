/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_first_letter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 21:07:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/11 02:18:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a first letter
**
** 1st parameter : input line
** 2nd parameter : parsing depth
** 3rd parameter : option
*/

void				ft_parse_first_letter(char *line, int depth)
{
	DEBUG_MODE ? ft_print_parsing(depth, "first_letter", "") : 0;
	if (!(*line &&
			(((ft_isalpha(*line)) && (*line != 'L')) || ft_isdigit(*line))))
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
}
