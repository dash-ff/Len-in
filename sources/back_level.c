/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:49:12 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/10 13:24:07 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		back_levels(t_lem *farm, t_room **rooms, int *stack)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = -1;
	k = 0;
	l = 1;
	while (++i < LEN)
	{
		j = 0;
		while (++j < LEN)
		{
			if (MAP[stack[i]][j] == 1)
			{
				if (rooms[j]->back_level == 0)
				{
					farm->back_level = rooms[stack[i]]->back_level - 1;
					stack[l++] = rooms[j]->index;
					rooms[j]->back_level = farm->back_level;
				}
			}
		}
	}
}
