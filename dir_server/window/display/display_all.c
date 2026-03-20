/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** display_all
*/

#include "server.h"

void display_all(window_server_t *win_info, sfRenderWindow *window)
{
    display_top(win_info, window);
    display_launch(win_info, window);
}
