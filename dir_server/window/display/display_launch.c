/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** display_launch
*/

#include "server.h"

void display_launch(window_server_t *win_info, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, win_info->launch_serv->rect, NULL);
    if (win_info->is_launch == false) {
        sfRenderWindow_drawText(window, win_info->launch_serv->launch, NULL);
        return;
    }
    if (win_info->is_launch == true) {
        sfRenderWindow_drawText(window, win_info->launch_serv->close, NULL);
        return;
    }
}