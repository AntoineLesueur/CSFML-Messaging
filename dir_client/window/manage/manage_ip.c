/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** manage_ip
*/

#include "client.h"

void manage_ip(win_info_t *win_info, sfEvent *event)
{
    if (event->type == sfEvtTextEntered) {
        if ((event->text.unicode >= '0' && event->text.unicode <= '9') || event->text.unicode == '.') {
            win_info->get_ip->str_ip[win_info->get_ip->index] = event->text.unicode;
            win_info->get_ip->index++;
        }
    }
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyBack) {
            win_info->get_ip->index--;
            if (win_info->get_ip->index < 0)
                win_info->get_ip->index = 0;
            win_info->get_ip->str_ip[win_info->get_ip->index] = '\0';
        }
    }
}