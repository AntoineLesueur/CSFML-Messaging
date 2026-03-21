/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** init_client
*/

#include "client.h"

static int create_socket(client_info_t *client_info)
{
    client_info->socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (client_info->socket_fd < 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int init_client(client_info_t *client_info)
{
    if (create_socket(client_info) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
