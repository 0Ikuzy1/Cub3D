/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:02:10 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/13 22:34:40 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	rotate_player(t_player *player, float angle_speed)
{
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

static void	move_with_slide(t_player *player, t_game *game, float dx, float dy)
{
	float	try_x;
	float	try_y;
	float	epsilon;
	float	check_x;
	float	check_y;

	epsilon = 22.6f;
	try_x = player->x + dx;
	try_y = player->y + dy;
	if (dx > 0)
		check_x = try_x + epsilon;
	else
		check_x = try_x - epsilon;
	if (!touch(check_x, player->y, game))
		player->x = try_x;
	if (dy > 0)
		check_y = try_y + epsilon;
	else
		check_y = try_y - epsilon;
	if (!touch(player->x, check_y, game))
		player->y = try_y;
}

static void	move_forward_backward(t_player *player, t_game *game,
		t_move_params params)
{
	float	dx;
	float	dy;

	dx = 0;
	dy = 0;
	if (player->key_up)
	{
		dx = params.cos_angle * params.speed;
		dy = params.sin_angle * params.speed;
		move_with_slide(player, game, dx, dy);
	}
	if (player->key_down)
	{
		dx = -params.cos_angle * params.speed;
		dy = -params.sin_angle * params.speed;
		move_with_slide(player, game, dx, dy);
	}
}

static void	move_sideways(t_player *player, t_game *game, t_move_params params)
{
	float	dx;
	float	dy;

	dx = 0;
	dy = 0;
	if (player->key_left)
	{
		dx = params.sin_angle * params.speed;
		dy = -params.cos_angle * params.speed;
		move_with_slide(player, game, dx, dy);
	}
	if (player->key_right)
	{
		dx = -params.sin_angle * params.speed;
		dy = params.cos_angle * params.speed;
		move_with_slide(player, game, dx, dy);
	}
}

void	move_player(t_player *player, t_game *game)
{
	t_move_params	params;
	float			angle_speed;

	params.speed = 6;
	angle_speed = 0.045;
	params.cos_angle = cos(player->angle);
	params.sin_angle = sin(player->angle);
	rotate_player(player, angle_speed);
	move_forward_backward(player, game, params);
	move_sideways(player, game, params);
}
