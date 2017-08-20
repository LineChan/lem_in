/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 00:31:35 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/20 18:47:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libs/libft/includes/libft.h"
# include "../libs/liblst/includes/liblst.h"

# define C_ROOM(it)		CONTAINEROF(it, t_room, lst)
# define R_REF(it)		(C_ROOM(it)->ref)
# define R_NAME(it)		(C_ROOM(it)->name)
# define ANTHILL		(anthill()->lst_head)
# define ROOM_NB		(anthill()->room_nb)
# define ANT_NB			(anthill()->ant_nb)
# define TUBE_NB		(anthill()->tube_nb)
# define START			(anthill()->start)
# define END			(anthill()->end)
/*
** Structures
*/
typedef struct			s_room
{
	int		ref;
	int		parent;
	char	*name;
	t_lst	lst;
}						t_room;

typedef struct			s_anthill
{
	int		room_nb;
	int		ant_nb;
	int		tube_nb;
	int		start;
	int		end;
	t_lst	lst_head;
}						t_anthill;

/*
** Prototypes
*/
t_anthill		*anthill(void);
void			ft_add_room(const int ref,
							const int parent,
							const char *name);
#endif
