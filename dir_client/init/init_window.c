/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** init_window
*/

#include "client.h"

static int init_rect(win_info_t *win_info)
{
    win_info->all_mess->rect = sfRectangleShape_create();
    if (!win_info->all_mess->rect)
        return EXIT_FAILURE;
    win_info->write_mess->rect = sfRectangleShape_create();
    if (!win_info->write_mess->rect)
        return EXIT_FAILURE;
    win_info->connect_butt->connect = sfText_create();
    if (!win_info->connect_butt->connect)
        return EXIT_FAILURE;
    win_info->connect_butt->rect = sfRectangleShape_create();
    if (!win_info->connect_butt->rect)
        return EXIT_FAILURE;
    win_info->get_ip->rect = sfRectangleShape_create();
    if (!win_info->get_ip->rect)
        return EXIT_FAILURE;
    win_info->get_ip->ip = sfText_create();
    if (!win_info->get_ip->ip)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int init_window(win_info_t *win_info)
{
    win_info->is_connect = false;
    win_info->all_mess = malloc(sizeof(*win_info->all_mess));
    if (!win_info->all_mess)
        return EXIT_FAILURE;
    win_info->write_mess = malloc(sizeof(*win_info->write_mess));
    if (!win_info->write_mess)
        return EXIT_FAILURE;
    win_info->connect_butt = malloc(sizeof(*win_info->connect_butt));
    if (!win_info->connect_butt)
        return EXIT_FAILURE;
    win_info->get_ip = malloc(sizeof(*win_info->get_ip));
    if (!win_info->get_ip)
        return EXIT_FAILURE;
    if (init_rect(win_info) == EXIT_FAILURE)
        return EXIT_FAILURE;
    win_info->get_ip->index = 0;
    return EXIT_SUCCESS;
}
