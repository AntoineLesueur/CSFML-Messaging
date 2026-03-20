/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** init_serv
*/

#include <ifaddrs.h>
#include <fcntl.h>
#include "server.h"

static void check_name(server_info_t *serv_info, struct ifaddrs *ifaddr)
{
    struct sockaddr_in *sa_in = malloc(sizeof(*sa_in));
    char *name = ifaddr->ifa_name;

    if (!sa_in)
        return;
    if (strcmp(name, "lo") != 0 && strncmp(name, "docker", strlen("docker")) != 0) {
        sa_in = (struct sockaddr_in *)ifaddr->ifa_addr;
        inet_ntop(AF_INET, &sa_in->sin_addr, serv_info->ip_server, INET_ADDRSTRLEN);
    }
    return;
}

static int get_ip_serv(server_info_t *serv_info)
{
    struct ifaddrs *ifaddr;
    struct ifaddrs *tmp;

    serv_info->ip_server = malloc(INET_ADDRSTRLEN);
    if (!serv_info->ip_server)
        return EXIT_FAILURE;
    if (getifaddrs(&ifaddr) == -1)
        return EXIT_FAILURE;
    tmp = ifaddr;
    while (tmp != NULL) {
        if (tmp->ifa_addr != NULL && tmp->ifa_addr->sa_family == AF_INET) {
            check_name(serv_info, tmp);
        }
        tmp = tmp->ifa_next;
    }
    freeifaddrs(ifaddr);
    printf("%s\n", serv_info->ip_server);
    return EXIT_SUCCESS;
}

static void create_socket(server_info_t *serv_info)
{
    serv_info->socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_info->socket_fd < 0)
        return;
    fcntl(serv_info->socket_fd, F_SETFL, O_NONBLOCK);
}

static void fill_sa_in(server_info_t *serv_info)
{
    serv_info->sa_in.sin_family = AF_INET;
    serv_info->sa_in.sin_port = htons(serv_info->port);
    serv_info->sa_in.sin_addr.s_addr = INADDR_ANY;
}

static int bind_serv(server_info_t *serv_info)
{
    int bind_res = bind(serv_info->socket_fd, (struct sockaddr *)&(serv_info->sa_in), sizeof(serv_info->sa_in));

    if (bind_res < 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static int listen_serv(server_info_t *serv_info)
{
    int listen_res = listen(serv_info->socket_fd, MAXLOG);

    if (listen_res < 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int init_info_serv(server_info_t *serv_info)
{
    if (get_ip_serv(serv_info) == EXIT_FAILURE)
        return EXIT_FAILURE;
    create_socket(serv_info);
    fill_sa_in(serv_info);
    if (bind_serv(serv_info) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (listen_serv(serv_info) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
