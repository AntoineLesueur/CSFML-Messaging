/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** init_position
*/

#include "server.h"
#include <stdbool.h>

static void init_sprite(sfSprite *rect, sfTexture *texture, float pos_x, float pos_y,
    float size_x, float size_y)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = pos_x;
    pos.y = pos_y;
    size.x = size_x;
    size.y = size_y;
    sfSprite_setTexture(rect, texture, true);
    sfSprite_setPosition(rect, pos);
    sfSprite_setScale(rect, size);
}

static void launch_butt(sfRectangleShape *rect, float pos_x, float pos_y, float size_x, float size_y)
{
    sfVector2f pos;
    sfVector2f size;
    sfColor color_butt = sfColor_fromRGB(56, 62, 71);

    pos.x = pos_x;
    pos.y = pos_y;
    size.x = size_x;
    size.y = size_y;
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, color_butt);
}

static void init_text(sfText *text, float pos_x, float pos_y, int size, char *txt, sfColor *color)
{
    sfVector2f pos;
    sfFont *arial = sfFont_createFromFile("./dir_server/Font/ARIAL.TTF");

    pos.x = pos_x;
    pos.y = pos_y;
    sfText_setFont(text, arial);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, size);
    sfText_setString(text, txt);
    sfText_setFillColor(text, *color);
}

void init_position(window_server_t *win_info, server_info_t *serv_info)
{
    init_sprite(win_info->stat->rect, win_info->texture_rect, 20, 10, 3.3, 3);
    init_sprite(win_info->stat->rect_ip, win_info->texture_rect, 20, 150, 3.3, 3);
    init_text(win_info->stat->status, 50, 2, 100, "STATUS : ", &sfWhite);
    init_text(win_info->stat->off, 500, 2, 100, "OFFLINE", &sfRed);
    init_text(win_info->stat->on, 500, 2, 100, "ONLINE", &sfGreen);
    init_text(win_info->stat->port, 1200, 2, 100, "PORT : 8080", &sfWhite);
    init_text(win_info->stat->ip_txt, 50, 140, 100, "IP : ", &sfWhite);
    init_text(win_info->stat->ip, 230, 140, 100, serv_info->ip_server, &sfWhite);
    launch_butt(win_info->launch_serv->rect, 1420, 900, 400, 150);
    win_info->launch_serv->bound = sfRectangleShape_getGlobalBounds(win_info->launch_serv->rect);
    init_text(win_info->launch_serv->launch, 1450, 927, 80, "LAUNCH", &sfWhite);
    init_text(win_info->launch_serv->close, 1480, 927, 80, "CLOSE", &sfWhite);
}
