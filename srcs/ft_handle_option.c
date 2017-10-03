/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:42:36 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/03 18:03:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Handle options
**
** 1st parameter : number of arguments
** 2nd parameter : list of arguments
** 3rd parameter : option
*/

void		ft_handle_option(int ac, char **av, int option[])
{
	option[0] = 0;
	option[1] = 0;
	if (ac > 1)
	{
		++av;
		if (!ft_strcmp("--parsing", *av))
		{
			option[0] = 1;
			++av;
		}
		if (*av && !ft_strncmp("--shortest_path=", *av, 16))
		{
			*av += 16;
			option[1] = ft_atoi(*av);
		}
	}
}
