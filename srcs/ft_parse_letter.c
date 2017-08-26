/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 00:30:45 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 22:32:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there are letters in the input
*/
int					ft_parse_letter(char *line)
{
	size_t		count;

	ft_printf("--------{YELLOW:START} ft_parse_letter --> '%s'\n", line);
	count = 0;
	while (ft_isascii(*line) && (*line != ' '))
	{
		++line;
		++count;
	}
	ft_printf("--------{YELLOW:END  } ft_parse_letter --> '%d'\n", count);
	return (count);
}
