/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:48:19 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/30 12:49:37 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			is_space(char line)
{
	return (line == ' ' ? OK : ERROR);
}

int			is_hyphen(char line)
{
	return (line == '-' ? OK : ERROR);
}