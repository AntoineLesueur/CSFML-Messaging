/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** client
*/

#ifndef CLIENT_H
    #define CLIENT_H

    #include <SFML/Graphics.h>

    #include <sys/socket.h>
    #include <arpa/inet.h>

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    #undef EXIT_FAILURE
    #define EXIT_FAILURE 84
    #undef EXIT_SUCCESS
    #define EXIT_SUCCESS 0

typedef struct lst_mess_s {
    char *message;
    sfText *text;
    struct lst_mess_s *next;
    sfVector2f pos;
} lst_mess_t;

typedef struct {
    sfRectangleShape *rect;
    sfText *connect;
    sfFloatRect bound;
} connect_butt_t;

typedef struct {
    char str_ip[BUFSIZ];
    int index;
    sfRectangleShape *rect;
    sfText *ip;
} get_ip_t;

typedef struct {
    sfRectangleShape *rect;
} box_mess_t;

typedef struct {
    sfRectangleShape *rect;
} box_write_t;

typedef struct {
    box_mess_t *all_mess;
    box_write_t *write_mess;
    connect_butt_t *connect_butt;
    get_ip_t *get_ip;
    bool is_connect;
} win_info_t;

typedef struct {
    int socket_fd;
    int ip_serv;
    char *str_ip;
    struct sockaddr_in sa_in;
    int index;
    sfText *mess;
    char message[BUFSIZ];
} client_info_t;

int init_all(void);
int init_window(win_info_t *win_info);
int init_client(client_info_t *client_info);
void init_rects(win_info_t *win_info, client_info_t *client_info);
int connect_client(client_info_t *client_info);
void init_sa_in(win_info_t *win_info, client_info_t *client_info);

void open_window(win_info_t *win_info, client_info_t *client_info);

void manage_window(win_info_t *win_info, sfRenderWindow *window, sfEvent *event, client_info_t *client_info, lst_mess_t **lst_mess);
void manage_ip(win_info_t *win_info, sfEvent *event);
void manage_mess(win_info_t *win_info, client_info_t *client_info, sfRenderWindow *window,
    sfEvent *event, lst_mess_t **lst_mess);

void display_menu(win_info_t *win_info, sfRenderWindow *window);
void display_messaging(win_info_t *win_info, sfRenderWindow *window, client_info_t *client_info, lst_mess_t *lst);

void hover(sfRenderWindow *window, win_info_t *win_info);
void clicked(sfEvent *event, win_info_t *win_info, client_info_t *client_info);

void push_back(char *mess, lst_mess_t **lst);

#endif
