/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** display_top
*/

#include "server.h"

void display_top(window_server_t *win_info, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, win_info->stat->rect, NULL);
    sfRenderWindow_drawSprite(window, win_info->stat->rect_ip, NULL);
    sfRenderWindow_drawText(window, win_info->stat->status, NULL);
    sfRenderWindow_drawText(window, win_info->stat->port, NULL);
    sfRenderWindow_drawText(window, win_info->stat->ip_txt, NULL);
    sfRenderWindow_drawText(window, win_info->stat->ip, NULL);
    if (win_info->is_launch ==  false)
        sfRenderWindow_drawText(window, win_info->stat->off, NULL);
    if (win_info->is_launch ==  true)
        sfRenderWindow_drawText(window, win_info->stat->on, NULL);
}
