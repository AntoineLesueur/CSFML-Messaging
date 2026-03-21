/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** hover
*/

#include "client.h"

void hover(sfRenderWindow *window, win_info_t *win_info)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
    sfColor hover_color = sfColor_fromRGB(39, 43, 46);
    sfColor not_hover = sfColor_fromRGB(56, 62, 71);

    if (sfFloatRect_contains(&(win_info->connect_butt->bound), pos_mouse.x, pos_mouse.y)) {
        sfRectangleShape_setFillColor(win_info->connect_butt->rect, hover_color);
    } else {
        sfRectangleShape_setFillColor(win_info->connect_butt->rect, not_hover);
    }
}