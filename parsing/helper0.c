/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 22:19:52 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/13 23:25:39 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	draw_map(t_game *game)
{
	char	**map;
	int		color;
	int		y;
	int		x;
	t_point	pos;

	map = game->map;
	color = 0x0000FF;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (map[y][x] == '1')
			{
				pos.x = x * BLOCK;
				pos.y = y * BLOCK;
				draw_square(pos, BLOCK, color, game);
			}
			x++;
		}
		y++;
	}
}

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

bool	check_adjacent(t_game *game, t_grid_pos grid, t_sub_pos sub)
{
	if (sub.x < 0.05 && grid.x > 0 && game->map[grid.y][grid.x - 1] == '1')
		return (true);
	if (sub.x > 0.95 && grid.x < game->map_width - 1 && game->map[grid.y][grid.x
		+ 1] == '1')
		return (true);
	if (sub.y < 0.05 && grid.y > 0 && game->map[grid.y - 1][grid.x] == '1')
		return (true);
	if (sub.y > 0.95 && grid.y < game->map_height - 1 && game->map[grid.y
			+ 1][grid.x] == '1')
		return (true);
	return (false);
}

bool	touch(float px, float py, t_game *game)
{
	t_grid_pos	grid;
	t_sub_pos	sub;

	grid.x = (int)(px / BLOCK);
	grid.y = (int)(py / BLOCK);
	if (grid.y < 0 || grid.y >= game->map_height || grid.x < 0
		|| grid.x >= game->map_width)
		return (true);
	if (game->map[grid.y][grid.x] == '1')
		return (true);
	sub.x = fmod(px, BLOCK) / BLOCK;
	sub.y = fmod(py, BLOCK) / BLOCK;
	return (check_adjacent(game, grid, sub));
}

void	init_game(t_game *game, t_map *map, t_parse *color)
{
	init_player(&game->player, map->player_dir, map);
	game->map = map->map;
	game->map_width = map->map_w;
	game->map_height = map->map_h;
	game->floor_color = get_color(color, 'F');
	game->ceiling_color = get_color(color, 'C');
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line,
			&game->endian);
	load_all_textures(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_hook(game->win, 17, 0, handle_close, game);
}
