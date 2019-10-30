/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <brickon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:34:16 by brickon-          #+#    #+#             */
/*   Updated: 2019/10/29 14:21:09 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_init_image(t_all *all, int i)
{
	all->vv->spd = 77;
	all->vv->mlx_ptr = mlx_init();
	all->vv->win_ptr = mlx_new_window(all->vv->mlx_ptr, all->vv->w,
				all->vv->h, "Lem-in");
	all->vv->img_ptr = mlx_new_image(all->vv->mlx_ptr, all->vv->w, all->vv->h);
	all->vv->img_2ptr = mlx_new_image(all->vv->mlx_ptr, 5, 5);
	all->vv->i_data = mlx_get_data_addr(all->vv->img_ptr, &(all->vv->bpp),
				&(all->vv->size_line), &(all->vv->endian));
	all->vv->img_2 = mlx_get_data_addr(all->vv->img_2ptr, &(all->vv->bpp),
				&(all->vv->size_line), &(all->vv->endian));
	all->rooms[0]->w = 70;
	all->rooms[0]->h = 596;
	all->rooms[all->farm->c_rooms - 1]->w = 2400;
	all->rooms[all->farm->c_rooms - 1]->h = 596;
	all->vv->x_1 = 0;
	all->vv->y_1 = 0;
	while (i < all->vv->w * all->vv->h)
	{
		*(int *)(all->vv->i_data + (i * 4)) = 0xDE181818;
		i++;
	}
}

void	ft_fill_back_ground(t_all *all)
{
	int i;
	int j;

	i = -1;
	while (++i < all->farm->c_rooms)
		ft_serch_links(all->vv, all->farm, all->rooms, i);
	i = -1;
	while (++i < all->farm->c_rooms)
	{
		j = -1;
		while (++j < 25)
		{
			*(int *)(all->vv->i_data + (((all->rooms[i]->w + j % 5) +
			(all->rooms[i]->h + j / 5) * all->vv->w) * 4)) = 0xCC55CC / 2 +
			*(int *)(all->vv->i_data + (((all->rooms[i]->w + j % 5) +
			(all->rooms[i]->h + j / 5) * all->vv->w) * 4)) + 0xEE000000;
		}
	}
}

void	ft_fill_ant(t_all *all)
{
	int x;
	int y;
	
	y = 0;
	while (y < 5)
	{
		x = 0;
		while(x < 5)
		{
			*(int *)(all->vv->img_2 + ((x + y * 5) * 4)) = 0xFFFFFF;
			x++;
		}
		y++;
	}
}
