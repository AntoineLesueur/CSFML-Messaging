/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** display_mess
*/

#include "client.h"

void display_messaging(win_info_t *win_info, sfRenderWindow *window, client_info_t *client_info, lst_mess_t *lst)
{
    lst_mess_t *tmp = lst;

    sfRenderWindow_drawRectangleShape(window, win_info->all_mess->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, win_info->write_mess->rect, NULL);
    sfText_setString(client_info->mess, client_info->message);
    sfRenderWindow_drawText(window, client_info->mess, NULL);
    while (tmp != NULL) {
        sfRenderWindow_drawText(window, tmp->text, NULL);
        tmp = tmp->next;
    }
}