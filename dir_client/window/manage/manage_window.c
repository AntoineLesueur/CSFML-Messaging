/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** manage_window
*/

#include "client.h"

void manage_window(win_info_t *win_info, sfRenderWindow *window, sfEvent *event)
{
    if (win_info->is_connect == false)
        manage_ip(win_info, event);
}
