/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:28:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/31 17:59:54 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** All adjancy matrix related functions
*/
int					**matrix(void)
{
	static int		**ptr;
	int				n;

	if (!ptr)
	{
		n = 0;
		if (!(ptr = (int **)ft_memalloc(sizeof(int *) * ROOM_NB)))
			ft_exit(11);
		while (n < ROOM_NB)
			if (!(ptr[n++] = ft_memalloc(sizeof(int) * ROOM_NB)))
				ft_exit(11);
	}
	return (ptr);
}

void				ft_set_matrix(const int ref_1,
									const int ref_2,
									const int value)
{
	MATRIX[ref_1][ref_2] = value;
	MATRIX[ref_2][ref_1] = value;
}

void				ft_del_matrix(void)
{
	int			**ptr;
	int			n;

	ptr = matrix();
	n = 0;
	while (n < ROOM_NB)
		free((void *)ptr[n++]);
	free((void *)ptr);
	ptr = 0;
}

void				ft_print_matrix(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < ROOM_NB)
	{
		ft_printf("[ ");
		while (j < ROOM_NB)
		{
			ft_printf("%d ", MATRIX[i][j]);
			++j;
		}
		ft_printf("]\n");
		j ^= j;
		++i;
	}
}
