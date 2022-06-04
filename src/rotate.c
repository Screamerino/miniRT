/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:41:49 by bstrong           #+#    #+#             */
/*   Updated: 2022/03/25 19:11:05 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	deg2rad(float deg)
{
	return (deg / 57.29578);
}

void	rotate_cam_x(t_cam *cam, float alpha)
{
	float	pre_y;
	float	r_alpha;

	r_alpha = deg2rad(alpha);
	pre_y = cam->orient.y;
	cam->orient.y = pre_y * cos(r_alpha) + cam->orient.z * sin(r_alpha);
	cam->orient.z = -pre_y * sin(r_alpha) + cam->orient.z * cos(r_alpha);
}

void	rotate_cam_y(t_cam *cam, float alpha)
{
	float	pre_x;
	float	r_alpha;

	r_alpha = deg2rad(alpha);
	pre_x = cam->orient.x;
	cam->orient.x = pre_x * cos(r_alpha) + cam->orient.z * sin(r_alpha);
	cam->orient.z = -pre_x * sin(r_alpha) + cam->orient.z * cos(r_alpha);
}

void	rotate_cam_z(t_cam *cam, float alpha)
{
	float	pre_x;
	float	pre_y;
	float	r_alpha;

	r_alpha = deg2rad(alpha);
	pre_x = cam->orient.x;
	pre_y = cam->orient.y;
	cam->orient.x = pre_x * cos(r_alpha) - pre_y * sin(r_alpha);
	cam->orient.y = pre_x * sin(r_alpha) + pre_y * cos(r_alpha);
}
