/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** open_window
*/

#include "server.h"
#include <sys/select.h>

static void close_event(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void open_window(server_info_t *serv_info, window_server_t *win_info)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "SERVER", sfClose | sfResize, NULL);
    sfEvent event = {0};
    sfColor background = sfColor_fromRGB(22, 35, 52);

    fd_set all_fds;
    sfRenderWindow_setFramerateLimit(window, 60);
    if (!window)
        return;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            close_event(window, &event);
            manage_window(&event, window, win_info);
        }
        sfRenderWindow_clear(window, background);
        display_all(win_info, window);
        if (win_info->is_launch == true)
            manage_server(serv_info, &all_fds);
        sfRenderWindow_display(window);
    }
    destroy_all(win_info, serv_info);
    sfRenderWindow_destroy(window);
}
