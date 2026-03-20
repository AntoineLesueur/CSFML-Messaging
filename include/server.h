/*
** EPITECH PROJECT, 2026
** Messagerie
** File description:
** server
*/

#ifndef SERVER_H
    #define SERVER_H

    #include <SFML/Graphics.h>

    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <sys/select.h>

    #define MAXLOG 20

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>


    #undef EXIT_FAILURE
    #define EXIT_FAILURE 84
    #undef EXIT_SUCCESS
    #define EXIT_SUCCESS 0

typedef struct {
    sfRectangleShape *rect;
    sfText *launch;
    sfText *close;
    sfFloatRect bound;
} launch_t;

typedef struct {
    sfSprite *rect;
    sfText *status;
    sfText *on;
    sfText *off;
    sfText *port;
    sfText *ip;
    sfText *ip_txt;
    sfSprite *rect_ip;
} stat_rect_t;

typedef struct {
    sfTexture *texture_rect;
    stat_rect_t *stat;
    launch_t *launch_serv;
    bool is_launch;
} window_server_t;

typedef struct {
    int socket_fd;
    int port;
    char *ip_server;
    struct sockaddr_in sa_in;
    int max_fd;
    int array_fd[MAXLOG];
    char message[BUFSIZ];
} server_info_t;

int init_all(void);
int init_launch(launch_t *launch);
int init_info_serv(server_info_t *serv_info);
int init_struct_stat_window(stat_rect_t *stat_window);
void init_position(window_server_t *win_info, server_info_t *serv_info);

void open_window(server_info_t *serv_info, window_server_t *win_info);

void display_all(window_server_t *win_info, sfRenderWindow *window);
void display_top(window_server_t *win_info, sfRenderWindow *window);
void display_launch(window_server_t *win_info, sfRenderWindow *window);

void manage_window(sfEvent *event, sfRenderWindow *window, window_server_t *win_info);
void manage_server(server_info_t *serv_info, fd_set *all_fds);

void hover(window_server_t *win_info, sfRenderWindow *window);
void clicked(window_server_t *win_info, sfEvent *event);

int run_serv(server_info_t *serv_info, fd_set *all_fds);
void set_new_client(server_info_t *serv_info, int i, fd_set *all_fds);
void new_client(server_info_t *serv_info);
void remove_client(server_info_t *serv_info, int index);
void new_message(server_info_t *serv_info, int sender);

void destroy_all(window_server_t *win_info, server_info_t *serv_info);

#endif
