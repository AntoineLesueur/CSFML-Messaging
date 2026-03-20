/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** main
*/

#include "server.h"

int main(void)
{
    if (init_all() == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
