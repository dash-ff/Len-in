#include "../includes/lem_in.h"




int		ft_keys(int key, t_viz *vv)
{
	if (key == 24 && vv->spd > 3)
		vv->spd--;
	if (key == 27)
		vv->spd++;
	if (key == 53)
		say_bay(vv);
	return (0);
}

int		say_bay(t_viz *vv)
{
	int status;

	if (vv->mus)
	{
		system("pkill afplay");
		vv->status = pthread_join(vv->thread, (void**)&vv->status_addr);
	}
	(void)vv;
	exit(0);
}

void	free_nah(t_viz *vv, t_lem *farm, t_room **rooms)
{
	vv->mlx_ptr = NULL;
}

int		ft_get_color(t_viz *vv, t_lem *farm)
{
	int color;

	color = 0;
	if ((vv->i % 4 == 0) || (farm->c_rooms < 150))
	{
		if ((vv->i + vv->j) % 5 == 0)
			color += 0xAA0000;
		if ((vv->i + vv->j) % 5 == 1)
			color += 0xAA;
		if ((vv->i + vv->j) % 5 == 2)
			color += 0xAAAA00;
		if ((vv->i + vv->j) % 5 == 3)
			color += 0xAAAA;
		if ((vv->i + vv->j) % 5 == 4)
			color += 0xAA00AA;
		return(color);
	}
	return(((0xFF / (vv->i + 1)) << 16) + (0xFF / (vv->j + 1)) + 0x6000);
}


void	ft_xy(t_viz *vv)
{
	vv->delta_x = abs(vv->x_1 - vv->x_0);
	vv->delta_y = abs(vv->y_1 - vv->y_0);
	vv->sign_x = vv->x_0 < vv->x_1 ? 1 : -1;
	vv->sign_y = vv->y_0 < vv->y_1 ? 1 : -1;
	vv->error = vv->delta_x - vv->delta_y;
	vv->br_y = vv->y_0;
	vv->br_x = vv->x_0;
}

void	ft_plot_links(t_viz *vv, t_lem *farm, t_room **rooms)
{
	ft_xy(vv);
	while (vv->br_x != vv->x_1 || vv->br_y != vv->y_1)
	{
			*(int *)(vv->i_data + ((vv->br_x + vv->br_y * vv->w) * 4)) = ft_get_color(vv, farm);
		vv->error2 = vv->error * 2;
		if (vv->error2 < vv->delta_x)
		{
			vv->error += vv->delta_x;
			vv->br_y += vv->sign_y;
		}
		if (vv->error2 > -(vv->delta_y))
		{
			vv->error -= vv->delta_y;
			vv->br_x += vv->sign_x;
		}
	}

}

void	ft_serch_links(t_viz *vv, t_lem *farm, t_room **rooms, int i)
{
	int j;

	j = i + 1;
	while(j < farm->c_rooms)
	{
		if (farm->map[j][i] == 1)
		{
			vv->x_0 = rooms[i]->w + 2;
			vv->y_0 = rooms[i]->h + 2;
			vv->x_1 = rooms[j]->w + 2;
			vv->y_1 = rooms[j]->h + 2;
			vv->i = i;
			vv->j = j;
 			ft_plot_links(vv, farm, rooms);
		}
		j++;
	}

}

void	ft_plot_step(t_all *all, int i)
{
	all->start_w = all->ants[i]->start_w;
	all->start_h = all->ants[i]->start_h;
	all->end_w = all->ants[i]->end_w;
	all->end_h = all->ants[i]->end_h;
	all->now_w = ((all->end_w - all->start_w) / (double)all->vv->spd) * all->fps + all->start_w;
	all->now_h = ((all->end_h - all->start_h) / (double)all->vv->spd) * all->fps + all->start_h;
	mlx_put_image_to_window(all->vv->mlx_ptr, all->vv->win_ptr, all->vv->img_2ptr, all->now_w, all->now_h);
}

void	ft_plot_last_step(t_all *all, int i)
{
	all->start_w = all->ants[i]->start_w;
	all->start_h = all->ants[i]->start_h;
	all->end_w = all->ants[i]->end_w;
	all->end_h = all->ants[i]->end_h;

	all->now_w = ((all->end_w - all->start_w) / (double)all->vv->spd) * all->fps + all->start_w;
	all->now_h = ((all->end_h - all->start_h) / (double)all->vv->spd) * all->fps + all->start_h;
	mlx_put_image_to_window(all->vv->mlx_ptr, all->vv->win_ptr, all->vv->img_2ptr, all->now_w, all->now_h);
}

int		ploting_steps(t_all *all)
{
	int i;

	i = 0;
	mlx_put_image_to_window(all->vv->mlx_ptr, all->vv->win_ptr, all->vv->img_ptr, 0, 0);
	while (i < all->farm->ants)
	{
		if (all->ants[i]->marching == 0)
			mlx_put_image_to_window(all->vv->mlx_ptr, all->vv->win_ptr, all->vv->img_2ptr, all->rooms[0]->w, all->rooms[0]->h);
		if (all->ants[i]->marching == 2)
		{
			if (all->farm->ant_count == all->farm->ants && all->fps == all->vv->spd - 1)
				return(1);
			ft_plot_last_step(all, i);
		}
		if (all->ants[i]->marching == 1)
			ft_plot_step(all, i);
		i++;
	}
	mlx_put_image_to_window(all->vv->mlx_ptr, all->vv->win_ptr, all->vv->img_2ptr, all->now_w, all->now_h);
	all->fps++;
	return(1);
}


int		transfer(t_all *all)
{
	if (all->fps >= all->vv->spd)
	{
		lets_go(all->farm, all->rooms, &(all->ants), all->vv);
		if (all->ants[0]->marching == 0)
				mlx_put_image_to_window(all->vv->mlx_ptr, all->vv->win_ptr, all->vv->img_2ptr, all->rooms[0]->w, all->rooms[0]->h);
		all->fps = 0;
		return (1);
	}
	else
		return(ploting_steps(all));
}
 

void	ft_display(t_viz *vv, t_lem *farm, t_room **rooms, t_ant ***ants)	
{
	t_all all;

	all.ants = *ants;
	all.farm = farm;
	all.rooms = rooms;
	all.vv = vv;
	ft_init_image(&all, 0);
	ft_fill_back_ground(&all);
	ft_fill_ant(&all);
	all.fps = vv->spd;
	mlx_put_image_to_window(vv->mlx_ptr, vv->win_ptr, vv->img_ptr, 0, 0);
	mlx_hook(vv->win_ptr, 2, 0, ft_keys, vv);
	mlx_hook(vv->win_ptr, 17, 0, say_bay, vv);
	mlx_loop_hook(vv->mlx_ptr, transfer,  &all);
	mlx_loop(vv->mlx_ptr);
}
