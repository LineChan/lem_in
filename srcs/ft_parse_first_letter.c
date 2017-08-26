/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_first_letter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 21:07:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 20:51:49 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a first letter
**
** 1st parameter : line to be checked
*/
int				ft_parse_first_letter(char *line)
{
	ft_printf("------------{YELLOW:START} first_letter -->  '%s'\n", line);
	if ((ft_isascii(*line)) && (*line != 'L')
				&& (*line != '#') && *line)
	{
		ft_printf("------------{YELLOW:END  } first_letter -->  '%s' {GREEN:OK}\n", line);
		return (1);
	}
	ft_printf("------------{YELLOW:END  } first_letter -->  '%s' {RED:KO}\n", line);
	return (0);
}
