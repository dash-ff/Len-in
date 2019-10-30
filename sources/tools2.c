/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:48:13 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/21 18:59:10 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void            write_room(t_lem *farm, t_room **rooms, int i, int j)
{
    green();
    write(1, "[", 1);
    reset();
    write(1, rooms[WAYS[j][i]]->name, ft_strlen(rooms[WAYS[j][i]]->name));
    green();
    write(1, "] ", 2);
    reset();
}

void            write_steps(t_lem *farm, int i, int j)
{
    write(1, " - ", 3);
    cyan();
    ft_putnbr(WAYS[j][i]);
    reset();
}
