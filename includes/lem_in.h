/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 00:31:35 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 20:30:49 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libs/libft/includes/libft.h"
# include "../libs/liblst/includes/liblst.h"

# define C_ROOM(it)		CONTAINEROF(it, t_room, lst)
# define R_REF(it)		(C_ROOM(it)->ref)
# define R_NAME(it)		(C_ROOM(it)->name)
# define ANTHILL		(anthill()->room_head)
# define ROOM_NB		(anthill()->room_nb)
# define ANT_NB			(anthill()->ant_nb)
# define TUBE_NB		(anthill()->tube_nb)
# define START			(anthill()->start_ref)
# define END			(anthill()->end_ref)

# define SHORTEST_PATH	(shortest_path()->result_head)
# define SP_NB		(shortest_path()->shortest_path_nb)
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
	int		start_ref;
	int		end_ref;
	t_lst	room_head;
}						t_anthill;

typedef struct			s_shortest_path
{
	int		shortest_path_nb;
	t_lst	result_head;
}						t_shortest_path;

typedef struct			s_result
{
	t_lst	lst;
	t_lst	room_head;
}						t_result;
/*
** Prototypes
*/
t_anthill			*anthill(void);
t_shortest_path		*shortest_path(void);
void				ft_del_singl_anthill(void);
void				ft_del_singl_shortest_path(void);
void				ft_add_room(const char *name);
void				ft_add_shortest_path(void);
void				ft_del_shortest_path(t_result *path);
void				ft_del_room(t_lst *src);
#endif
