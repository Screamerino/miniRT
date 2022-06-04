/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:11:04 by lcoreen           #+#    #+#             */
/*   Updated: 2022/06/04 10:26:32 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "minirt.h"

static int	close_esc(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	clear_lst_light(&data->light);
	free_list_obj(&data->obj);
	exit(0);
	return (0);
}

static int	check_button(int button) {
	return (button != ESC && button != KEY_PLUS && button != KEY_MINUS &&
		button != KEY_UP && button != KEY_LEFT && button != KEY_DOWN &&
		button != KEY_RIGHT && button != KEY_A && button != KEY_S &&
		button != KEY_D && button != KEY_Q && button != KEY_W && button != KEY_E);
}

static void	move_cam(int k, t_data *data)
{
	if (k == KEY_LEFT)
		data->cam.pos = vec_sub(&data->cam.pos, &data->cam.right);
	if (k == KEY_RIGHT)
		data->cam.pos = vec_sum(&data->cam.pos, &data->cam.right);
	if (k == KEY_UP)
		data->cam.pos = vec_sum(&data->cam.pos, &data->cam.up);
	if (k == KEY_DOWN)
		data->cam.pos = vec_sub(&data->cam.pos, &data->cam.up);
	if (k == KEY_PLUS)
		data->cam.pos = vec_sum(&data->cam.pos, &data->cam.orient);
	if (k == KEY_MINUS)
		data->cam.pos = vec_sub(&data->cam.pos, &data->cam.orient);
}

static void	rotate_cam(int k, t_data *data)
{
	float	step;

	step = 1;
	if (k == KEY_Q)
		rotate_cam_x(&data->cam, step);
	if (k == KEY_A)
		rotate_cam_x(&data->cam, -step);
	if (k == KEY_W)
		rotate_cam_y(&data->cam, step);
	if (k == KEY_S)
		rotate_cam_y(&data->cam, -step);
	if (k == KEY_E)
		rotate_cam_z(&data->cam, step);
	if (k == KEY_D)
		rotate_cam_z(&data->cam, -step);
}

int	key_hook(int button, t_data *data)
{
	if (check_button(button))
		return 1;
	if (button == ESC)
		close_esc(data);
	if (button == KEY_A || button == KEY_S || button == KEY_D ||
		button == KEY_Q || button == KEY_W || button == KEY_E)
		rotate_cam(button, data);
	if ((button >= KEY_LEFT && button <= KEY_DOWN) ||
		button == KEY_PLUS || button == KEY_MINUS)
		move_cam(button, data);
	if (fabs(data->cam.orient.y) != 1)
		data->cam.up = new_vector(0, 1, 0);
	else
		data->cam.up = new_vector(1, 0, 0);
	data->cam.right = vec_mul(&data->cam.up, &data->cam.orient);
	data->cam.up = vec_mul(&data->cam.orient, &data->cam.right);
	vec_norm(&data->cam.orient);
	draw(data);
	return (0);
}
