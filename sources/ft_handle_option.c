/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:42:36 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/17 12:36:30 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Handle options
**
** 1st parameter : number of arguments
** 2nd parameter : list of arguments
*/

int			ft_handle_option(int ac, char **av)
{
	if (ac > 1)
	{
		++av;
		if (*av && !ft_strncmp("--shortest_path=", *av, 16))
		{
			*av += 16;
			return (ft_atoi(*av));
		}
	}
	return (0);
}
