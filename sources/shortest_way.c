/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rage <rage@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:19:25 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/13 23:27:47 by rage             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void        shortest_way(t_lem *farm, t_room **rooms)
{
	int		i;
	int		size;
	int		min;

	i = LEN - 1;
	size = 0;
	if (!(farm->shortest = (int *)malloc(sizeof(int) * (LEVEL + 1))))
		exit(0);
	ft_bzero(farm->shortest, LEVEL * 4);
	farm->shortest[0] = farm->end->index;
	while (i > 0)
	{
		min = find_min_link(farm, rooms, i);
		fill_short_way(farm, rooms, min);
		i = min;
		size++;
	}
	reverse_int_tab(farm->shortest, size);
}

int			find_min_link(t_lem *farm, t_room **rooms, int i)
{
	int		j;
	int		levels;
	int		min;

	j = -1;
	levels = 1000000;
	min = 0;
	while (++j < LEN)
	{
		if (MAP[i][j] == 1)
		{
			if (levels > rooms[j]->level)
			{
				min = j;
				levels = rooms[j]->level;
			}
		}
	}
	return (min);
}

void		fill_short_way(t_lem *farm, t_room **rooms, int min)
{
	int		j;

	j = 1;
	while (j < LEVEL)
	{
		if (farm->shortest[j])
			j++;
		else
			break ;
	}
	farm->shortest[j] = rooms[min]->index;
}

void		reverse_int_tab(int *shortest, int size)
{
	int		i;
	int		tmp;

	i = 0;
	while (i <= size)
	{
		tmp = shortest[i];
		shortest[i++] = shortest[size];
		shortest[size--] = tmp;
	}
}
