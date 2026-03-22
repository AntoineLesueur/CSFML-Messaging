/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** linked_list_mess
*/

#include "client.h"

static void update_pos(lst_mess_t *lst, float new_y)
{
    lst_mess_t *tmp = lst;

    while (tmp != NULL) {
        tmp->pos.y -= new_y;
        sfText_setPosition(tmp->text, tmp->pos);
        tmp = tmp->next;
    }
}

static void delete_node(lst_mess_t **lst)
{
    lst_mess_t *tmp = *lst;

    if (*lst == NULL)
        return;
    *lst = (*lst)->next;
    free(tmp->message);
    sfText_destroy(tmp->text);
    free(tmp);
}

static int count_node(lst_mess_t *lst)
{
    int cpt = 0;
    lst_mess_t *tmp = lst;

    while (tmp != NULL) {
        cpt++;
        tmp = tmp->next;
    }
    return cpt;
}

void push_back(char *mess, lst_mess_t **lst)
{
    lst_mess_t *new_node = malloc(sizeof(*new_node));
    lst_mess_t *tmp = *lst;
    sfFont *arial = sfFont_createFromFile("./dir_client/Font/ARIAL.TTF");

    if (!new_node)
        return;
    new_node->message = strdup(mess);
    new_node->text = sfText_create();
    new_node->pos.x = 300;
    new_node->pos.y = 800;
    new_node->next = NULL;
    sfText_setFont(new_node->text, arial);
    sfText_setCharacterSize(new_node->text, 40);
    sfText_setColor(new_node->text, sfBlack);
    sfText_setPosition(new_node->text, new_node->pos);
    sfText_setString(new_node->text, new_node->message);
    if (*lst == NULL) {
        *lst = new_node;
        return;
    }
    update_pos(*lst, 50);
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new_node;
    if (count_node(*lst) > 16)
        delete_node(lst);
}
