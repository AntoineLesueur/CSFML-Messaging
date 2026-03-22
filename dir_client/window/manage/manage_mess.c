/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** manage_mess
*/

#include "client.h"

void recv_mess(lst_mess_t **lst, client_info_t *client_info)
{
    char mess_recv[BUFSIZ];
    int recv_res = recv(client_info->socket_fd, mess_recv, BUFSIZ, MSG_DONTWAIT);

    if (recv_res < 0)
        return;
    mess_recv[recv_res] = '\0';
    push_back(mess_recv, lst);
}

static void send_mess(client_info_t *client_info, sfEvent *event, lst_mess_t **lst_mess)
{
    int len = strlen(client_info->message);
    char *mess_tmp = strdup(client_info->message);

    if (event->key.code == sfKeyEnter) {
        push_back(mess_tmp, lst_mess);
        send(client_info->socket_fd, mess_tmp, len, 0);
        for (int i = 0; i < len; i++) {
            client_info->message[i] = '\0';
        }
        client_info->index = 0;
    }
}

static void delete_char(client_info_t *client_info, sfEvent *event)
{
    if (event->key.code == sfKeyBack) {
        client_info->index--;
        if (client_info->index < 0)
            client_info->index = 0;
        client_info->message[client_info->index] = '\0';
    }
}

void manage_mess(client_info_t *client_info, sfEvent *event, lst_mess_t **lst_mess)
{
    if (event->type == sfEvtTextEntered) {
        if (event->text.unicode >= 32 && event->text.unicode <= 126) {
            client_info->message[client_info->index] = event->text.unicode;
            client_info->index++;
        }
    }
    if (event->type == sfEvtKeyPressed) {
        delete_char(client_info, event);
        send_mess(client_info, event, lst_mess);
    }
    recv_mess(lst_mess, client_info);
}