/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** new_message
*/

#include "server.h"

static void send_to_other(server_info_t *serv_info, int sender)
{
    for (int i = 0; i < MAXLOG; i++) {
        if (serv_info->array_fd[i] > 0 && i != sender) {
            send(serv_info->array_fd[i], serv_info->message, BUFSIZ, 0);
        }
    }
}

void new_message(server_info_t *serv_info, int sender)
{
    int recv_res = recv(serv_info->array_fd[sender], serv_info->message, BUFSIZ, 0);

    if (recv_res <= 0)
        remove_client(serv_info, sender);
    send_to_other(serv_info, sender);
}
