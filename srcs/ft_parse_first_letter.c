/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_first_letter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 21:07:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/28 14:23:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a first letter
**
** 1st parameter : line to be checked
*/
void				ft_parse_first_letter(char *line)
{
	ft_printf("------------{YELLOW:START} first_letter -->  '%s'\n", line);
	if (!((ft_isascii(*line)) && (*line != 'L')
				&& (*line != '#') && *line))
		ft_exit(6);
		ft_printf("------------{YELLOW:END  } first_letter -->  '%s' {GREEN:OK}\n", line);
}
