/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** destroy_all
*/

#include "server.h"

void destroy_all(window_server_t *win_info, server_info_t *serv_info)
{
    sfSprite_destroy(win_info->stat->rect);
    sfSprite_destroy(win_info->stat->rect_ip);
    sfText_destroy(win_info->stat->ip);
    sfText_destroy(win_info->stat->ip_txt);
    sfText_destroy(win_info->stat->off);
    sfText_destroy(win_info->stat->on);
    sfText_destroy(win_info->stat->port);
    sfText_destroy(win_info->stat->status);
    sfTexture_destroy(win_info->texture_rect);
    sfText_destroy(win_info->launch_serv->close);
    sfText_destroy(win_info->launch_serv->launch);
    sfRectangleShape_destroy(win_info->launch_serv->rect);
    free(win_info->launch_serv);
    free(win_info->stat);
    free(win_info);
    free(serv_info->ip_server);
    free(serv_info);
}
