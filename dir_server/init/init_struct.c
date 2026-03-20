/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** init_struct
*/

#include "server.h"

static void init_struct_server(server_info_t *serv_info)
{
    serv_info->ip_server = NULL;
    serv_info->socket_fd = 0;
    serv_info->port = 8080;
    serv_info->max_fd = 0;
    memset(serv_info->array_fd, 0, sizeof(serv_info->array_fd));
}

static int init_struct_window(window_server_t *window_info)
{
    window_info->stat = malloc(sizeof(*window_info->stat));
    window_info->launch_serv = malloc(sizeof(*window_info->launch_serv));

    window_info->texture_rect = sfTexture_createFromFile("./dir_server/Sprite/Rectangle_Sprite.png", NULL);
    if (!window_info->texture_rect)
        return EXIT_FAILURE;
    if (!window_info->launch_serv)
        return EXIT_FAILURE;
    if (init_struct_stat_window(window_info->stat) == EXIT_FAILURE)
        return EXIT_FAILURE;
    window_info->is_launch = false;
    return EXIT_SUCCESS;
}

int init_all(void)
{
    server_info_t *serv_info = malloc(sizeof(*serv_info));
    window_server_t *window_info = malloc(sizeof(*window_info));

    if (!serv_info)
        return EXIT_FAILURE;
    if (!window_info) {
        free(serv_info);
        return EXIT_FAILURE;
    }
    init_struct_server(serv_info);
    if (init_struct_window(window_info) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (init_info_serv(serv_info) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (init_launch(window_info->launch_serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    init_position(window_info, serv_info);
    open_window(serv_info, window_info);
    return EXIT_SUCCESS;
}
