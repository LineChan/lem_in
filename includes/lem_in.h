/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 00:31:35 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/28 12:54:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libs/libft/includes/libft.h"
# include "../libs/liblst/includes/liblst.h"

# define C_ROOM(it)		CONTAINEROF(it, t_room, lst)
# define R_REF(it)		(C_ROOM(it)->ref)
# define R_NAME(it)		(C_ROOM(it)->name)
# define R_SIZE(it)		(C_ROOM(it)->name_size)
# define R_X(it)		(C_ROOM(it)->x)
# define R_Y(it)		(C_ROOM(it)->y)
# define R_ANT(it)		(C_ROOM(it)->ant)
# define ANTHILL		(anthill()->room_head)
# define ROOM_NB		(anthill()->room_nb)
# define ANT_NB			(anthill()->ant_nb)
# define TUBE_NB		(anthill()->tube_nb)
# define START_REF		(anthill()->start_ref)
# define END_REF		(anthill()->end_ref)

# define C_RESULT(it)	CONTAINEROF(it, t_result, lst)
# define PATH(it)		(C_RESULT(it)->room_head)
# define PATH_REF(it)	(C_RESULT(it)->ref)
# define PATH_LEN(it)	(C_RESULT(it)->len)
# define SHORTEST_PATH	(shortest_path()->result_head)
# define SP_NB			(shortest_path()->shortest_path_nb)
# define FIRST_SP_LEN	(PATH_LEN(SHORTEST_PATH.next))

# define MATRIX			(matrix())
/*
** Flags
*/
# define FLAG_START		0x1
# define FLAG_END		0x10
# define COMMAND_START	(*flag & FLAG_START)
# define COMMAND_END	(*flag & FLAG_END)

/*
** Structures
*/

typedef struct			s_error
{
	const char		message[100];
}						t_error;


typedef struct			s_room
{
	int			ref;
	int			x;
	int			y;
	int			ant;
	char		*name;
	size_t		name_size;
	t_lst		lst;
}						t_room;

typedef struct			s_anthill
{
	int			room_nb;
	int			ant_nb;
	int			tube_nb;
	int			start_ref;
	int			end_ref;
	t_lst		room_head;
}						t_anthill;

typedef struct			s_shortest_path
{
	int		shortest_path_nb;
	t_lst	result_head;
}						t_shortest_path;

typedef struct			s_result
{
	int		ref;
	int		len;
	t_lst	lst;
	t_lst	room_head;
}						t_result;
/*
** Prototypes
*/
t_anthill			*anthill(void);
t_shortest_path		*shortest_path(void);
int					**matrix(void);

void				ft_set_matrix(const int ref_1,
									const int ref_2,
									const int value);
void				ft_del_matrix(void);
void				ft_reset_matrix(void);

void				ft_del_singl_anthill(void);
void				ft_del_singl_shortest_path(void);
void				ft_del_everything(void);
void				ft_add_room(const char *name,
								const size_t size,
								const int x,
								const int y);
void				ft_add_shortest_path(void);
void				ft_del_shortest_path(t_lst *path);
void				ft_del_room(t_lst *src);
void				ft_exit(const int ret);
void				ft_clear_unlinked_room(void);
void				ft_handle_shortest_path_nb(int ac, char **av);
void				ft_handle_option(int ac, char **av, int option[2]);
void				ft_ant_repartition(void);
void				ft_copy_end_room_to_path(void);

int					ft_parse(void);
void				ft_parse_ant(char **line, int depth);
int					ft_parse_room_list(char **line, int depth);
void				ft_parse_tube_list(char **line, int depth);
int					ft_parse_room_id(char *line, int *x, int *y, int depth);
void				ft_parse_duplicate_name_and_coordinate(const char *line, const int ret, const int x, const int y);
int					ft_parse_tube_id(char *line, int *ref_1, int *ref_2, int depth);
int					ft_parse_room_name(char *line, int depth);
void				ft_parse_first_letter(char *line, int depth);
int					ft_parse_letter(char *line, int depth);
int					ft_parse_new_line(char **line);
int					ft_parse_nb(char **cursor, int depth);
int					ft_parse_command(char **line, int depth, int *flag);
t_lst				*ft_find_room_with_name(t_lst *node, const char *room_name, const int len);
t_lst				*ft_find_room_with_ref(t_lst *node, const int len);

int					ft_iddsf(void);

void				ft_print_matrix(void);
void				ft_print_room_list(t_lst *head);
void				ft_print_shortest_path_list(void);
void				ft_print_parsing(const int depth,
									const char *name,
									const char *line);
void				ft_print_output(void);
void				ft_send_quick_solution(void);
#endif
