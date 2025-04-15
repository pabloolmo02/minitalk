# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Paths
PRINTF_DIR = printff
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

# Archivos fuente y binarios
SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

NAME_CLIENT = client
NAME_SERVER = server

# Reglas
all: $(PRINTF_LIB) $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(PRINTF_LIB)

$(NAME_SERVER): $(OBJS_SERVER) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) $(PRINTF_LIB)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	make -C $(PRINTF_DIR) fclean

re: fclean all
