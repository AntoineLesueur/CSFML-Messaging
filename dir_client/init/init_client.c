/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** init_client
*/

#include "client.h"
#include <fcntl.h>

static int create_socket(client_info_t *client_info)
{
    client_info->socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (client_info->socket_fd < 0)
        return EXIT_FAILURE;
    fcntl(client_info->socket_fd, F_SETFL, O_NONBLOCK);
    return EXIT_SUCCESS;
}

int connect_client(client_info_t *client_info)
{
    int connect_res = connect(client_info->socket_fd, (struct sockaddr *)&(client_info->sa_in), sizeof(client_info->sa_in));

    if (connect_res < 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int init_client(client_info_t *client_info)
{
    client_info->str_ip = NULL;
    client_info->index = 0;
    client_info->mess = sfText_create();
    if (create_socket(client_info) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
