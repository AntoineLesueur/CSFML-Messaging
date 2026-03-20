/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** clicked
*/

#include "server.h"

void clicked(window_server_t *win_info, sfEvent *event)
{
    sfVector2f click_pos;

    if (event->type == sfEvtMouseButtonPressed) {
        click_pos.x = event->mouseButton.x;
        click_pos.y = event->mouseButton.y;
        if (sfFloatRect_contains(&(win_info->launch_serv->bound), click_pos.x, click_pos.y)) {
            if (win_info->is_launch == false) {
                win_info->is_launch = true;
                return;
            }
            if (win_info->is_launch == true) {
                win_info->is_launch = false;
                return;
            }
        }
    }
}