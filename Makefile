##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Compile all files
##

SRC_CLIENT	=	./dir_client/main.c									\
				./dir_client/init/init_all.c						\
				./dir_client/init/init_client.c						\
				./dir_client/init/init_window.c						\
				./dir_client/init/init_rects.c						\
				./dir_client/window/open_window.c					\
				./dir_client/window/display/display_mess.c			\
				./dir_client/window/display/display_menu.c			\
				./dir_client/window/manage/manage_window.c			\
				./dir_client/window/manage/manage_ip.c				\

SRC_SERVER	=	./dir_server/main.c										\
				./dir_server/init/init_serv.c							\
				./dir_server/init/init_struct.c							\
				./dir_server/init/init_window_serv.c					\
				./dir_server/init/init_rects.c							\
				./dir_server/window/open_window.c						\
				./dir_server/window/display/display_all.c				\
				./dir_server/window/display/display_top.c				\
				./dir_server/window/display/display_launch.c			\
				./dir_server/window/states/hover.c						\
				./dir_server/window/states/clicked.c					\
				./dir_server/window/manage/manage_window.c				\
				./dir_server/window/manage/server_run/manage_server.c	\
				./dir_server/window/manage/server_run/run_serv.c		\
				./dir_server/window/manage/server_run/set_new_client.c	\
				./dir_server/window/manage/server_run/new_message.c		\
				./dir_server/destroy/destroy_all.c						\



OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

MKDIR = mkdir

BUILD = build

BUILD_CLIENT = build/clients

BUILD_SERV = build/server

MV = mv

CLIENT	=	client

SERVER	= server

CC		=	gcc

CSFML =	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CP	=	cp

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-iquote ./include

THREAD = -pthread

all:	$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJ_CLIENT)
		$(MKDIR) -p $(BUILD_CLIENT)
		$(CC) $(CPPFLAGS) -o $(CLIENT) $(OBJ_CLIENT) $(CSFML)
		$(MV) $(OBJ_CLIENT) $(BUILD_CLIENT)

$(SERVER):	$(OBJ_SERVER)
		$(MKDIR) -p $(BUILD_SERV)
		$(CC) $(CPPFLAGS) $(THREAD) -o $(SERVER) $(OBJ_SERVER) $(CSFML)
		$(MV) $(OBJ_SERVER) $(BUILD_SERV)

server: $(SERVER)

client: $(CLIENT)

debug_client:	$(OBJ_CLIENT)
		$(MKDIR) -p $(BUILD_CLIENT)
		$(CC) $(CPPFLAGS) -o $(CLIENT) $(OBJ_CLIENT) $(CSFML) -g3
		$(MV) $(OBJ_CLIENT) $(BUILD_CLIENT)

debug_serv:	$(OBJ_SERVER)
		$(MKDIR) -p $(BUILD_SERV)
		$(CC) $(CPPFLAGS) $(THREAD) -o $(SERVER) $(OBJ_SERVER) $(CSFML) -g3
		$(MV) $(OBJ_SERVER) $(BUILD_SERV)

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	$(RM) -r $(BUILD)

fclean:	clean
	$(RM) $(CLIENT) $(SERVER)

re:	fclean all

.PHONY: all clean fclean re client server debug_client debug_serv
