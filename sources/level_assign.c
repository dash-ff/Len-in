/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:55:36 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/10 13:24:27 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void        level_assign(t_lem *farm, t_room **rooms, int *stack)
{
	int		i;
	int		j;
	int		l;

	i = -1;
	l = 1;
	while (++i < LEN)
	{
		j = 0;
		while (++j < LEN)
		{
			if (MAP[stack[i]][j] == 1)
			{
				if (rooms[j]->level == 0)
				{
					farm->level = rooms[stack[i]]->level + 1;
					stack[l++] = rooms[j]->index;
					rooms[j]->level = farm->level;
				}
			}
		}
	}
}
