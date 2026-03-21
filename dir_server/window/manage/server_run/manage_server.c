/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** manage_server
*/

#include "server.h"
#include <sys/select.h>

void manage_server(server_info_t *serv_info, fd_set *all_fds)
{
    if (run_serv(serv_info, all_fds) == EXIT_FAILURE)
        return;
}
