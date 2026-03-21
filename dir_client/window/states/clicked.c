/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** clicked
*/

#include "client.h"

void clicked(sfEvent *event, win_info_t *win_info, client_info_t *client_info)
{
    if (event->type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&(win_info->connect_butt->bound), event->mouseButton.x, event->mouseButton.y)) {
            init_sa_in(win_info, client_info);
            win_info->is_connect = true;
        }
        if (client_info->ip_serv <= 0)
            win_info->is_connect = false;
    }
}