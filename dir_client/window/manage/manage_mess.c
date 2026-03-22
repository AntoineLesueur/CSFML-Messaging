/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** manage_mess
*/

#include "client.h"

static void send_mess(client_info_t *client_info, sfEvent *event, lst_mess_t **lst_mess)
{
    int len = strlen(client_info->message);
    int send_res = 0;
    char *mess_tmp = client_info->message;

    if (event->key.code == sfKeyEnter) {
        push_back(mess_tmp, lst_mess);
        for (int i = 0; i < len; i++) {
            client_info->message[i] = '\0';
        }
        client_info->index = 0;
    }
    ///send_res = send(client_info->socket_fd, client_info->message, len, 0);
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

void manage_mess(win_info_t *win_info, client_info_t *client_info, sfRenderWindow *window,
    sfEvent *event, lst_mess_t **lst_mess)
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
}