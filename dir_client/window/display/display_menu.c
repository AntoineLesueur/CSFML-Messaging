/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** display_menu
*/

#include "client.h"

void display_menu(win_info_t *win_info, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, win_info->connect_butt->rect, NULL);
    sfRenderWindow_drawText(window, win_info->connect_butt->connect, NULL);
    sfRenderWindow_drawRectangleShape(window, win_info->get_ip->rect, NULL);
    sfText_setString(win_info->get_ip->ip, win_info->get_ip->str_ip);
    sfRenderWindow_drawText(window, win_info->get_ip->ip, NULL);
}