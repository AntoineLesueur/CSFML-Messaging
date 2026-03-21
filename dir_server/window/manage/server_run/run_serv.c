/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** run_serv
*/

#include "server.h"
#include <sys/select.h>

int run_serv(server_info_t *serv_info, fd_set *all_fds)
{
    FD_ZERO(all_fds);
    FD_SET(serv_info->socket_fd, all_fds);
    serv_info->max_fd = serv_info->socket_fd;
    struct timeval tv = {0, 0};
    for (int i = 0; i < MAXLOG; i++) {
        set_new_client(serv_info, i, all_fds);
    }
    if (select(serv_info->max_fd + 1, all_fds, NULL, NULL, &tv) < 0)
        return EXIT_FAILURE;
    if (FD_ISSET(serv_info->socket_fd, all_fds))
        new_client(serv_info);
    for (int i = 0; i < MAXLOG; i++) {
        if (serv_info->array_fd[i] > 0 && FD_ISSET(serv_info->array_fd[i], all_fds))
            new_message(serv_info, i);
    }
    return EXIT_SUCCESS;
}
