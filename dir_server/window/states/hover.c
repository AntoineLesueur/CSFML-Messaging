/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** hover
*/

#include "server.h"

void hover(window_server_t *win_info, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfColor hover_color = sfColor_fromRGB(39, 43, 46);
    sfColor not_hover = sfColor_fromRGB(56, 62, 71);

    if (sfFloatRect_contains(&(win_info->launch_serv->bound), mouse_pos.x, mouse_pos.y)) {
        sfRectangleShape_setFillColor(win_info->launch_serv->rect, hover_color);
    } else {
        sfRectangleShape_setFillColor(win_info->launch_serv->rect, not_hover);
    }
}
