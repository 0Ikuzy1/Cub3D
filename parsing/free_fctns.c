#include "parsing.h"

void	free_parse(t_parse *parse)
{
    t_parse *tmp;
    while (parse)
    {
        tmp = parse->next;
        free(parse);
        parse = tmp;
    }
}

void	free_map(t_map *map)
{
    int i;
    if (!map) return;
    if (map->map)
    {
        for (i = 0; map->map[i]; i++)
            free(map->map[i]);
        free(map->map);
    }
    free(map);
}

void	free_textures_paths(t_textures *tex)
{
    if (!tex) return;
    free(tex->no_path);
    free(tex->so_path);
    free(tex->we_path);
    free(tex->ea_path);
}

void	free_game(t_game *game)
{
    if (!game) return;
    free_textures_paths(&game->textures);
    // Free other dynamically allocated members if any
}

void	destroy_all(t_game *game, t_map *map, t_parse *parse)
{
    free_game(game);
    free_map(map);
    free_parse(parse);
}
