/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimmer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:47:13 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/07 15:47:32 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void        ft_delete_one_by_one(t_lem *farm, t_room **rooms)
{
    int        i;

	i = -1;
    while(++i < farm->c_rooms)
    {
        if (rooms[i]->level == 1)
            start_trim(farm, rooms, i);
        else if (rooms[i]->back_level == -1)
            end_trim(farm, rooms, i);
    }
}

void		start_trim(t_lem *farm, t_room **rooms, int i)
{
	int		j;

	j = -1;
	while (++j < farm->c_rooms)
	{
		if (farm->map[j][i] == 1 && rooms[j]->level == 1)
		{
			farm->map[j][i] = 0;
			farm->map[i][j] = 0;
		}
	}
}

void		end_trim(t_lem *farm, t_room **rooms, int i)
{
	int		j;

	j = -1;
	while (++j < farm->c_rooms)
	{
		if (farm->map[j][i] == 1 && rooms[j]->back_level == -1)
		{
			farm->map[j][i] = 0;
			farm->map[i][j] = 0;
		}
	}
}
