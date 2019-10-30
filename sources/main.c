/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <brickon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:04:38 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/30 16:03:36 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <pthread.h>

void		error_output(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

void		init_struct(t_lem *farm)
{
	ANTS = '1';
	ROOMS = '1';
	LINKS = '1';
	farm->s = 0;
	farm->e = 0;
	farm->c_rooms = 0;
	farm->back_level = 0;
	farm->ant_count = 0;
	farm->lines = 0;
	farm->vizu = 0;
	farm->music = 0;
	farm->l = 0;
	farm->w = 0;
	farm->steps = 0;
}

void	ft_fill_coord(t_viz *vv, t_lem *farm, t_room **rooms)
{
	int x;
	int y;
	int i;

	i = 1;
	x = 0;
	y = 0;
	while (i < farm->c_rooms - 1)
	{
		rooms[i]->h = 50 + y * vv->size_room + vv->size_room / 2 - 2;
		if (y % 2)
			rooms[i]->w = 150 + x * vv->size_room + vv->size_room / 2 - 2;
		else
			rooms[i]->w = 150 + x * vv->size_room - 2;
		i++;
		y++;
		if (y >= vv->room_in_line)
		{
			y = 0;
			x++;
		}
	}
}

void			*music_power(void *lol)
{
	system("afplay ./bee.mp3 &");
	return (lol);
}


t_viz	*ft_init_visual(t_lem *farm)
{
	int tmp;
	
	t_viz 		*vv;
	if (!(vv = (t_viz *)malloc(sizeof(t_viz))))
		error_output();
	vv->w = 2500;
	vv->h = 1200;
	vv->color = 0xFFFFFF;
	vv->mus = 0;
	tmp = (farm->c_rooms % 2) ? farm->c_rooms - 1 : farm->c_rooms - 2;
	vv->raw_size_room = sqrt(tmp / 2);
	vv->room_in_line = (int)vv->raw_size_room;
	if (vv->raw_size_room != (double)vv->room_in_line)
		vv->room_in_line++;
	vv->size_room = (vv->h - 100) / vv->room_in_line;
	if (farm->music == 1 && farm->vizu == 1)
	{
		vv->status = pthread_create(&vv->thread, NULL, music_power, vv->lol);
		vv->mus = 1;
	}
	return (vv);
}

int			main(int ac, char **av)
{
	t_lem		farm;
	t_viz 		*vv;
	t_room		**rooms;
	t_ant		**ants;
	static char	*buf;

	init_struct(&farm);
	while (get_next_line(0, &(farm.line)) != 0)
	{
		ft_join_free(&(farm.line), "\n");
		write(1, farm.line, ft_strlen(farm.line));
		validation(farm.line, &farm, &buf, &rooms);
		free(farm.line);
	}
	if (farm.arl[1] != '2')
		error_output();
	find_shortest_way(&farm, rooms);
	find_not_crossing_ways(&farm, rooms);
	if (ac == 2)
		parce_arg(&farm, av[1]);
	vv = ft_init_visual(&farm);
	ft_fill_coord(vv, &farm,  rooms);
	ants_attack(&farm, rooms, &ants, vv);
	bonuses(&farm, rooms);
	exit(0);
}