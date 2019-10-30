/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <brickon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:04:25 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/29 13:18:39 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		attack_order(t_lem *farm, t_room **rooms, t_ant ***ants, t_viz *vv)
{
	int		i;
	int		j;
	int		ways[SLINKS];

	i = -1;
	j = 0;
	ft_bzero(ways, (SLINKS * 4));
	while (++i < farm->ants)
	{
		if (check_ways_num(farm, ants, ways, i) == OK)
		{
			ways[j++] = (*ants)[i]->way[0];
		}
	}
	// printf("%d count of rooms\n", j);
	// j = -1;
	// while (++j < SLINKS)
	// 	printf("%d\t", ways[j]);
	// printf("\n");
	if (farm->vizu == 1)
	{
		ft_display(vv, farm, rooms, ants);
	}
	else
		while (farm->ant_count != farm->ants)
			lets_go(farm, rooms, ants, vv);
}

int			check_ways_num(t_lem *farm, t_ant ***ants, int *ways, int i)
{
	int		j;

	j = -1;
	while (++j < SLINKS || ways[j] != 0)
		if ((*ants)[i]->way[0] == ways[j])
			return (ERROR);
	return (OK);
}

void		lets_go(t_lem *farm, t_room **rooms, t_ant ***ants, t_viz *vv)
{
	int		i;
	

	i = -1;
	farm->lines++;
	// if (farm->ant_count == farm->ants)
	// 	return ;
	// {
	// 	while (++i < )
	// }
	while (++i < farm->ants)
	{
		if ((*ants)[i]->marching == 2)
			(*ants)[i]->marching = 3;
		if ((*ants)[i]->marching == 0)
			start_march(rooms, ants, i, farm);
		else if ((*ants)[i]->marching == 1)
			keep_way(farm, rooms, ants, i);
	}

	// ft_join_free(&(farm->ant_output), "\n");
	write(1, "\n", 1);
}

void		start_march(t_room **rooms, t_ant ***ants, int i, t_lem *farm)
{
	if (rooms[(*ants)[i]->way[(*ants)[i]->i + 1]]->book == 0)
	{
		(*ants)[i]->marching = 1;
		(*ants)[i]->i++;
		(*ants)[i]->start_w = rooms[0]->w;
		(*ants)[i]->start_h = rooms[0]->h;
		(*ants)[i]->end_w = rooms[(*ants)[i]->way[(*ants)[i]->i]]->w;
		(*ants)[i]->end_h = rooms[(*ants)[i]->way[(*ants)[i]->i]]->h;

		
		rooms[(*ants)[i]->way[(*ants)[i]->i]]->book = 1;
		// ft_join_free(&(farm->ant_output), "L");
		write(1, "L", 1);
		// ft_join_free(&(farm->ant_output), ft_itoa((*ants)[i]->num));
		ft_putnbr((*ants)[i]->num);
		
		// ft_join_free(&(farm->ant_output), "-");
		write(1, "-", 1);
		// ft_join_free(&(farm->ant_output), rooms[(*ants)[i]->way[(*ants)[i]->i]]->name);
		write(1, rooms[(*ants)[i]->way[(*ants)[i]->i]]->name,
			ft_strlen(rooms[(*ants)[i]->way[(*ants)[i]->i]]->name));
		// ft_join_free(&(farm->ant_output), " ");
		write(1, " ", 1);
	}
}

void		keep_way(t_lem *farm, t_room **rooms, t_ant ***ants, int i)
{
	rooms[(*ants)[i]->way[(*ants)[i]->i]]->book = 0;
	
	(*ants)[i]->start_w = rooms[(*ants)[i]->way[(*ants)[i]->i]]->w;
	(*ants)[i]->start_h = rooms[(*ants)[i]->way[(*ants)[i]->i]]->h;
	(*ants)[i]->i++;
	(*ants)[i]->end_w = rooms[(*ants)[i]->way[(*ants)[i]->i]]->w;
	(*ants)[i]->end_h = rooms[(*ants)[i]->way[(*ants)[i]->i]]->h;
	
	if ((*ants)[i]->way[((*ants)[i]->i)] == farm->end->index)
	{
		(*ants)[i]->marching = 2;
		farm->ant_count += 1;
	}
	// ft_join_free(&(farm->ant_output), "L");
	write(1, "L", 1);
	// ft_join_free(&(farm->ant_output), ft_itoa((*ants)[i]->num));
	ft_putnbr((*ants)[i]->num);
	
	// ft_join_free(&(farm->ant_output), "-");
	write(1, "-", 1);

	// ft_join_free(&(farm->ant_output), rooms[(*ants)[i]->way[(*ants)[i]->i]]->name);
	write(1, rooms[(*ants)[i]->way[(*ants)[i]->i]]->name,
		ft_strlen(rooms[(*ants)[i]->way[(*ants)[i]->i]]->name));

	// ft_join_free(&(farm->ant_output), " ");
	write(1, " ", 1);
	// sleep(1);
}
