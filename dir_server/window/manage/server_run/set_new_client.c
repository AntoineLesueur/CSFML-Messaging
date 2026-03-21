/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** set_new_client
*/

#include "server.h"

static int add_client(server_info_t *serv_info, int new_fd)
{
    for (int i = 0; i < MAXLOG; i++) {
        if (serv_info->array_fd[i] == 0) {
            serv_info->array_fd[i] = new_fd;
            return i;
        }
    }
    return EXIT_FAILURE;
}

void remove_client(server_info_t *serv_info, int index)
{
    close(serv_info->array_fd[index]);
    serv_info->array_fd[index] = 0;
}

void new_client(server_info_t *serv_info)
{
    struct sockaddr_in sa_in;
    socklen_t len_sa_in = sizeof(sa_in);
    int new_fd = 0;
    int index = 0;

    new_fd = accept(serv_info->socket_fd, (struct sockaddr *)&sa_in, &(len_sa_in));
    if (new_fd < 0)
        return;
    index = add_client(serv_info, new_fd);
    if (index == EXIT_FAILURE) {
        close(new_fd);
        return;
    }
    return;
}

void set_new_client(server_info_t *serv_info, int i, fd_set *all_fds)
{
    FD_SET(serv_info->socket_fd, all_fds);
    if (serv_info->array_fd[i] > 0) {
        FD_SET(serv_info->array_fd[i], all_fds);
        if (serv_info->array_fd[i] > serv_info->max_fd)
            serv_info->max_fd = serv_info->array_fd[i];
    }
}
