/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** init_rects
*/

#include "client.h"

static void create_text(sfText *text, float pos_x, float pos_y, int size, char *string,
    sfFont *font, sfColor *color)
{
    sfVector2f pos;

    pos.x = pos_x;
    pos.y = pos_y;
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, size);
    sfText_setFillColor(text, *color);
    sfText_setFont(text, font);
    sfText_setString(text, string);
}

static void create_rect(sfRectangleShape *rect, float pos_x, float pos_y, float size_x,
    float size_y, sfColor *color)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = pos_x;
    pos.y = pos_y;
    size.x = size_x;
    size.y = size_y;
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, *color);
}

void init_rects(win_info_t *win_info, client_info_t *client_info)
{
    sfColor color_connect = sfColor_fromRGB(56, 62, 71);
    sfFont *arial = sfFont_createFromFile("./dir_client/Font/ARIAL.TTF");

    create_rect(win_info->connect_butt->rect, 670, 730, 550, 195, &color_connect);
    create_text(win_info->connect_butt->connect, 690, 770, 100, "CONNECT", arial, &sfWhite);
    create_rect(win_info->get_ip->rect, 600, 300, 700, 120, &sfWhite);
    create_text(win_info->get_ip->ip, 610, 300, 100, "", arial, &sfBlack);
    create_rect(win_info->all_mess->rect, 200, 50, 1400, 1000, &sfWhite);
    create_rect(win_info->write_mess->rect, 250, 940, 1300, 80, &sfWhite);
    sfRectangleShape_setOutlineThickness(win_info->write_mess->rect, 1);
    sfRectangleShape_setOutlineColor(win_info->write_mess->rect, sfBlack);
    create_text(client_info->mess, 260, 935, 40, "", arial, &sfBlack);
    win_info->connect_butt->bound = sfRectangleShape_getGlobalBounds(win_info->connect_butt->rect);
}
