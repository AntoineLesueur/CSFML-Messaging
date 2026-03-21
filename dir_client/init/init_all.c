/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** init_all
*/

#include "client.h"

int init_all(void)
{
    client_info_t *client_info = malloc(sizeof(*client_info));
    win_info_t *win_info = malloc(sizeof(*win_info));
    lst_mess_t *lst_mess = NULL;

    if (!client_info)
        return EXIT_FAILURE;
    if (!win_info) {
        free(client_info);
        return EXIT_FAILURE;
    }
    if (init_window(win_info) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (init_client(client_info) == EXIT_FAILURE)
        return EXIT_FAILURE;
    init_rects(win_info, client_info);
    open_window(win_info, client_info);
    return EXIT_SUCCESS;
}
