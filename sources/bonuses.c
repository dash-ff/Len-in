/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <brickon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:09:48 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/29 17:14:31 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void            bonuses(t_lem *farm, t_room **rooms)
{
	if (farm->l == 1)
		write_lines(farm);
	if (farm->steps == 1)
		write_with_steps(farm, rooms);
	else if (farm->w == 1)
		write_ways(farm, rooms);
}

void            write_lines(t_lem *farm)
{
	write(1, "\n", 1);
	write(1, "number of lines : ", 18);
	green();
	ft_putnbr(farm->lines);
	write(1, "\n\n", 2);
	reset();
}

void			write_ways(t_lem *farm, t_room **rooms)
{
	int		i;
	int		j;

	j = 0;
	write(1, "\n", 1);
	while (++j < SLINKS)
	{
		i = 0;
		if (WAYS[j][WAYS[j][LEVEL]] == farm->end->index)
		{
			while (++i < LEVEL)
			{
				if (rooms[WAYS[j][i]]->index != 0)
					write_room(farm, rooms, i, j);
			}
			write(1, "\n\n", 2);
		}
	}
	write(1, "\n", 1);
}

void			write_with_steps(t_lem *farm, t_room **rooms)
{
	int		i;
	int		j;

	j = 0;
	write(1, "\n", 1);
	while (++j < SLINKS)
	{
		i = 0;
		if (WAYS[j][WAYS[j][LEVEL]] == farm->end->index)
		{
			while (++i <= LEVEL)
			{
				if (i == LEVEL)
					write_steps(farm, i, j);
				else if (rooms[WAYS[j][i]]->index != 0)
					write_room(farm, rooms, i, j);
			}
			write(1, "\n\n", 2);
		}
	}
	write(1, "\n", 1);
}