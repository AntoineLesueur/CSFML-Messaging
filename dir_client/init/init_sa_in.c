/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** init_sa_in
*/

#include "client.h"

void init_sa_in(win_info_t *win_info, client_info_t *client_info)
{
    client_info->str_ip = malloc(sizeof(char) * (strlen(win_info->get_ip->str_ip) + 1));

    for (int i = 0; win_info->get_ip->str_ip[i] != '\0'; i++) {
        client_info->str_ip[i] = win_info->get_ip->str_ip[i];
    }
    client_info->sa_in.sin_family = AF_INET;
    client_info->sa_in.sin_port = htons(8080);
    client_info->ip_serv = inet_pton(AF_INET, client_info->str_ip, &(client_info->sa_in.sin_addr.s_addr));
}