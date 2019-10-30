/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <brickon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:39:04 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/29 17:40:18 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define BUFF_SIZE 7
# define OK 1
# define ERROR 0
# define KILL -1
# define LEVEL farm->level
# define SLINKS farm->start->links
# define ANTS farm->arl[0]
# define ROOMS farm->arl[1]
# define LINKS farm->arl[2]
# define LEN farm->c_rooms
# define MAP farm->map
# define WAYS farm->no_crossed_ways
# include <stdio.h>
# include "mlx.h"
# include "math.h"
#include <pthread.h>
# include "../libft/includes/libft.h"


typedef struct	s_viz
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*i_data;
	char		*img_2;
	void		*img_2ptr;
	double		raw_size_room;
	int			size_line2;
	int			endian2;
	int 		bpp2;
	// int			x;
	
	int			status_addr;
	int			mus;
	pthread_t	thread;
	int			status;
	void		*lol;


	int 		w;
	int			h;
	int			i;
	int			j;
	int			bpp;
	int			size_line;
	int			endian;
	int			error;
	int			error2;
	int			br_x;
	int			br_y;
	int			x_1;
	int			y_1;
	int			x_0;
	int			y_0;
	int			delta_x;
	int			delta_y;
	int			sign_x;
	int			sign_y;
	int	spd;


	// int			fps;
	int			room_in_line;
	int			color;
	int			size_room;
}				t_viz;


typedef struct	s_room
{
	char		*name;
	int			index;
	int			level:16;
	int			back_level:16;
	int			links;
	int			x;
	int			y;
	int			w;
	int			h;
	int			stop;
	int			fork;
	int			book;
}				t_room;

typedef struct	s_ant
{
	int			marching;
	int			*way;
	int			i;
	int			num;
	double 		start_w;
	double 		start_h;
	double		end_w;
	double 		end_h;
}				t_ant;


typedef struct	s_lem
{
	t_room		*start;
	t_room		*end;
	int			**map;
	int			**ways;
	int			**no_crossed_ways;
	int			*shortest;
	char 		*ant_output;
	char		arl[3];
	int			ants;
	int			level:16;
	int			back_level:16;
	int			s;
	int			e;
	int			c_rooms;
	int			ant_count;
	int			lines;
	int			stop_cond;
	int			vizu;
	int			music;
	int			l;
	int			steps;
	int			w;
	char 		*line;
}				t_lem;

typedef struct s_all
{
	t_viz *vv;
	t_lem *farm;
	t_room **rooms;
	t_ant **ants;

	int i;
	int fps;
	int j;
	double start_w;
	double start_h;
	double	end_w;
	double end_h;
	int	now_w;
	int now_h;
} 				t_all;


// vis
int		ft_get_color(t_viz *vv, t_lem *farm);
void	ft_xy(t_viz *vv);
void	ft_plot_links(t_viz *vv, t_lem *farm, t_room **rooms);
int		ft_keys(int key, t_viz *f);
int		say_bay(t_viz *f);
void	ft_fill_coord( t_viz *vv, t_lem *farm, t_room **rooms);
void	ft_serch_links(t_viz *vv, t_lem *farm, t_room **rooms, int i);
void	ft_display(t_viz *vv, t_lem *farm, t_room **rooms, t_ant ***ants);
// void	ft_speed(t_viz *vv, int flag);

void	ft_plot_last_step(t_all *all, int i);
void	ft_plot_step(t_all *all, int i);
int	ploting_steps(t_all *all);

//init im

void    ft_init_image(t_all *all, int i);
void    ft_fill_back_ground(t_all *all);
void	ft_fill_ant(t_all *all);

/*
** main.c
*/

t_viz			*ft_init_visual(t_lem *farm);
int				main(int ac, char **av);
void			init_struct(t_lem *farm);
void			error_output(void);

/*
** get_next_line.c
*/

int				get_next_line(const int fd, char **line);

/*
** validation.c
*/

void			validation(char *line, t_lem *farm, char **buf, t_room ***rooms);
void			valid_ants(char *line, t_lem *farm);
void			line_identificator(char *line, t_lem *farm);
void			first_valid(char *line, t_lem *farm);

/*
** valid_rooms.c
*/

void			valid_rooms(char *line, t_lem *farm, char **buf);
void			valid_start(t_lem *farm);
void			valid_end(t_lem *farm);
void			save_rooms(char *line, t_lem **farm, char **buf);
void			is_valid_line(char *line);

/*
** init_rooms.c
*/

void			start_room(char *line, t_lem **farm);
void			end_room(char *line, t_lem **farm);
void			valid_x(char *tmp);
void			valid_y(char *tmp);
void			fill_rooms(t_room *room, char **tmp, int i);

/*
** parse_rooms.c
*/

void			parse_and_create(t_lem *farm, char *buf, t_room ***rooms);
void			parse_rooms(t_lem *farm, char *buf, t_room ***rooms);
void	        create_map(t_lem *farm);
void			check_and_fill(t_room ***rooms, char *tmp, int i);
void			start_init(t_lem *farm, t_room ***rooms);
void			end_init(t_lem *farm, t_room ***rooms, int len);

/*
** valid_links.c
*/

void	        valid_links(char *line, t_lem *farm, t_room ***rooms);
void			parse_links(char *line, t_lem *farm, t_room ***rooms);
void			valid_name(t_lem *farm, t_room ***rooms, char *tmp);
int				init_index(t_lem *farm, t_room ***rooms, char *tmp);

/*
** check_chars.c
*/

int				is_space(char line);
int				is_hyphen(char line);

/*
** tools.c
*/

int 	        words_counter(char *line);
int 	        count_rooms(char *buf);
void			split_free(char **tmp);
int				count_links(int *arr);
void			clear_the_way(t_lem *farm, t_room **rooms, int j, int k);

/*
** level_assign.c
*/

void			level_assign(t_lem *farm, t_room **rooms, int *stack);
void			first_level(t_lem *farm, t_room **rooms, int * stack);
void			all_levels(t_lem *farm, t_room **rooms, int *stack);
void			next_level(t_lem *farm, t_room **rooms, int *stack);
void			init_level(t_lem *farm, t_room *rooms, int *stack);

/*
** find_shortest_way.c
*/

void			find_shortest_way(t_lem *farm, t_room **rooms);
void	        cut_deadlocks(t_lem *farm, t_room **rooms);
void	        cut_deadlocks2(t_lem *farm, t_room **rooms, int j);
void			ft_kill_loops(t_lem *farm, t_room **rooms);
// void	        fill_links(t_lem *farm, t_room **rooms);

/*
** shortest_way.c
*/

void			shortest_way(t_lem *farm, t_room **rooms);
int				find_min_link(t_lem *farm, t_room **rooms, int i);
void			fill_short_way(t_lem *farm, t_room **rooms, int min);
void			reverse_int_tab(int *shortest, int size);

/*
** back_level.c
*/

void			back_levels(t_lem *farm, t_room **rooms, int *stack);
void	        prev_level(t_lem *farm, t_room **rooms, int *stack);
void			first_prev_level(t_lem *farm, t_room **rooms, int *stack);
void			all_prev_levels(t_lem *farm, t_room **rooms, int *stack);
void			init_back_level(t_lem *farm, t_room *rooms, int *stack);

/*
** trimmer.c
*/

void        	ft_delete_one_by_one(t_lem *farm, t_room **rooms);
void			start_trim(t_lem *farm, t_room **rooms, int i);
void			end_trim(t_lem *farm, t_room **rooms, int i);

/*
** find_not_crossing_ways.c
*/

void			find_not_crossing_ways(t_lem *farm, t_room **rooms);
void			init_stack(t_lem *farm);
void			start_rooms_init(t_lem *farm, t_room **rooms);
void			how_many_forks(t_lem *farm, t_room **rooms, int j);
void			index_modifier(t_lem *farm, t_room **rooms, int j, int *i);
// void			lets_begin(t_lem *farm, t_room **rooms);
// void			choose_your_way(t_lem *farm, t_room **rooms, int i);

/*
** choose_ways.c
*/

void			what_we_should_do(t_lem *farm, t_room **rooms, int j);
void			fill_array(t_room *room, int *arr, int k, int *free);
void			one_free_way(t_lem *farm, t_room **rooms, int *arr, int i);
void			which_one_free_way(t_lem *farm, t_room **rooms, int *arr, int j);
void			to_much_free_ways(t_lem *farm, t_room **rooms, int *arr, int j);
// void			stop_equal_zero(t_lem *farm, t_room **rooms, int j, int i);
// void			stop_not_zero(t_lem *farm, t_room **rooms, int j, int i);
// void			another_way(t_lem *farm , t_room **rooms, int j, int *k);

/*
** occupied_rooms.c
*/

void			scouting(t_lem *farm, t_room **rooms, int i);
// void			this_way(t_lem *farm, t_room **rooms, int i, int j);
void			is_it_deadlock(t_lem *farm, t_room **rooms, int arr, int j);
int				find_free_room(t_lem *farm, t_room **rooms, int j, int k);
void			compare_free_ways(t_room **rooms, int way, int *nextway, int i);
void			turn_else_way(t_lem *farm, t_room **rooms, int j, int k);
void			cut_equal_ways(t_lem *farm, t_room **rooms, int j);

/*
** warriors_way.c
*/

void			warriors_way(t_lem *farm, t_room **rooms, int *arr, int j);
int				this_two_ways(t_lem *farm, t_room **rooms, int arr, int j);
int				find_free_ways(t_lem *farm, t_room **rooms, int j, int k);
int				this_way(t_lem *farm, t_room **rooms, int j, int k);
void			not_any_way(t_lem *farm, t_room **rooms, int *arr, int j);

/*
** ants_attack.c
*/

void			ants_attack(t_lem *farm, t_room **rooms, t_ant ***ants, t_viz *vv);
void			init_ants(t_lem *farm, t_ant ***ants, int *arr);
void			fill_ants(t_lem *farm, t_ant ***ants, int i, int *arr);
int				*give_way(t_lem *farm, int *arr);

/*
** attack_order.c
*/

void			attack_order(t_lem *farm, t_room **rooms, t_ant ***ants, t_viz *vv);
int				check_ways_num(t_lem *farm, t_ant ***ants, int *ways, int i);
void			lets_go(t_lem *farm, t_room **rooms, t_ant ***ants, t_viz *vv);
void			start_march(t_room **rooms, t_ant ***ants, int i, t_lem *farm);
void			keep_way(t_lem *farm, t_room **rooms, t_ant ***ants, int i);

/*
** bonuses.c
*/

void			bonuses(t_lem *farm, t_room **rooms);
void			write_lines(t_lem *farm);
void			write_ways(t_lem *farm, t_room **rooms);
void			write_with_steps(t_lem *farm, t_room **rooms);

/*
** colors.c
*/

void			red(void);
void			green(void);
void			reset(void);
void			cyan(void);

/*
** tools2.c
*/

void            write_room(t_lem *farm, t_room **rooms, int i, int j);
void            write_steps(t_lem *farm, int i, int j);

/*
** parce_arg.c
*/

void            parce_arg(t_lem *farm, char *ar);

#endif
