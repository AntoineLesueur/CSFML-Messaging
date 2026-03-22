/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** manage_window
*/

#include "client.h"

void manage_window(win_info_t *win_info, sfRenderWindow *window, sfEvent *event, client_info_t *client_info, lst_mess_t **lst_mess)
{
    hover(window, win_info);
    clicked(event, win_info, client_info);
    if (win_info->is_connect == false)
        manage_ip(win_info, event);
    if (win_info->is_connect == true) {
        manage_mess(win_info, client_info, window, event, lst_mess);
    }
}
