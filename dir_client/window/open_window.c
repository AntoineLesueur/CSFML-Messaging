/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** open_window
*/

#include "client.h"

static void close_event(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void open_window(win_info_t *win_info, client_info_t *client_info)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "CLIENT", sfClose | sfResize, NULL);
    sfEvent event = {0};
    sfColor background = sfColor_fromRGB(22, 35, 52);
    lst_mess_t *lst_mess = NULL;

    sfRenderWindow_setFramerateLimit(window, 60);
    if (!window)
        return;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            manage_window(win_info, window, &event, client_info, &lst_mess);
            close_event(window, &event);
        }
        sfRenderWindow_clear(window, background);
        if (win_info->is_connect == false)
            display_menu(win_info, window);
        if (win_info->is_connect == true)
            display_messaging(win_info, window, client_info, lst_mess);
        sfRenderWindow_display(window);
    }
}