/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <brickon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:19:11 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/29 17:34:16 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void        find_shortest_way(t_lem *farm, t_room **rooms)
{
	int     stack[LEN + 1];
	int		stack_back[LEN + 1];
	int     i;
	// int		j;
	int		one;

	write(1, "\n", 1);
	one = 0;
	i = -1;
	while (++i <= LEN)
		stack_back[i] = farm->end->index;
	ft_bzero(stack, (LEN + 1) * 4);
	cut_deadlocks(farm, rooms);
	level_assign(farm, rooms, stack);
	back_levels(farm, rooms, stack_back);
	shortest_way(farm, rooms);
	ft_kill_loops(farm, rooms);
	// i = -1;
	// while (++i < farm->c_rooms)
	// 	printf("%d\t", stack[i]);
	// printf("\n");
	// i = -1;
	// while (++i < farm->c_rooms)
	// 	printf("%d\t", rooms[stack[i]]->index);
	// printf("\n");
	// i = -1;
	// while (++i < farm->c_rooms)
	// 	printf("%s\t", rooms[stack[i]]->name);
	// printf("\n");
	/***********************************************/

	// i = -1;
	// while (++i < farm->c_rooms)
	// {
	// 	if (rooms[stack_back[i]]->links)
	// 	{
			// printf("%s\tname\n", rooms[stack[i]]->name);
			// printf("%d\ti\n", i);
			// printf("%d\tindex\n", rooms[stack[i]]->index);
			// printf("%d\tlevel\n\n", rooms[stack[i]]->level);
			// printf("%d\tback_level\n", rooms[stack_back[i]]->back_level);
			// printf("%d\tlinks\n\n", rooms[stack[i]]->links);
	// 	}
	// }
	// i = -1;
	// while (++i <= farm->c_rooms)
	// {
	// 	j = -1;
	// 	while (++j <= farm->c_rooms)
	// 	{
	// 		if (farm->map[i][j] == 1)
	// 			printf("\033[1;032m%d\033[0m ", farm->map[i][j]);
	// 		else if (j == i)
	// 			printf("\033[0;033m%d\033[0m ", farm->map[i][i]);
	// 		else
	// 			printf("\033[1;030m%d ", farm->map[i][j]);
	// 			one++;
	// 	}
	// 	printf("\n");
	// }
	// printf("%d = one\n", one);
	
	/***********************************************/
}

void        cut_deadlocks(t_lem *farm, t_room **rooms)
{
	// int     i;
	int     j;
	int		res;

	j = LEN - 1;
	res = 0;
	while (--j > 0)
		cut_deadlocks2(farm, rooms, j);
}

void        cut_deadlocks2(t_lem *farm, t_room **rooms, int j)
{
	int		i;
	
	i = LEN - 1;
	while(--i > 0)
	{
		if (MAP[j][i] == 1 && rooms[j]->links == 1)
		{
			MAP[i][j] = 0;
			MAP[j][i] = 0;
			rooms[j]->links--;
			rooms[i]->links--;
			if (rooms[i]->links == 1)
				cut_deadlocks2(farm, rooms, i);
		}
	}
}

void		ft_kill_loops(t_lem *farm, t_room **rooms)
{
	int		i;
	int		j;

	i = 0;
	while (++i < LEN)
	{
		
		if (rooms[i]->back_level == 0 && i != farm->end->index)
		{
			j = -1;
			rooms[i]->links = 0;
			while (++j < LEN)
			{
				if (MAP[i][j] == 1)
				{
					MAP[i][j] = 0;
					MAP[j][i] = 0;
					rooms[j]->links--;
				}
			}
		}
	}
}
