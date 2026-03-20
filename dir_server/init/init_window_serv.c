/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** init_window_serv
*/

#include "server.h"

int init_launch(launch_t *launch)
{
    launch->close = sfText_create();
    if (!launch->close)
        return EXIT_FAILURE;
    launch->launch = sfText_create();
    if (!launch->launch)
        return EXIT_FAILURE;
    launch->rect = sfRectangleShape_create();
    if (!launch->rect)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int init_struct_stat_window(stat_rect_t *stat_window)
{
    stat_window->ip = sfText_create();
    if (!stat_window->ip)
        return EXIT_FAILURE;
    stat_window->off = sfText_create();
    if (!stat_window->off)
        return EXIT_FAILURE;
    stat_window->on = sfText_create();
    if (!stat_window->on)
        return EXIT_FAILURE;
    stat_window->ip_txt = sfText_create();
    if (!stat_window->ip_txt)
        return EXIT_FAILURE;
    stat_window->port = sfText_create();
    if (!stat_window->port)
        return EXIT_FAILURE;
    stat_window->status = sfText_create();
    if (!stat_window->status)
        return EXIT_FAILURE;
    stat_window->rect = sfSprite_create();
    if (!stat_window->rect)
        return EXIT_FAILURE;
    stat_window->rect_ip = sfSprite_create();
    if (!stat_window->rect_ip)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
