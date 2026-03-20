/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** manage_window
*/

#include "server.h"

void manage_window(sfEvent *event, sfRenderWindow *window, window_server_t *win_info)
{
    hover(win_info, window);
    clicked(win_info, event);
}
