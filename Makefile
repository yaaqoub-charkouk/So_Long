CC = cc
LIB = /Users/ycharkou/
CFLAGS = -Wall -Wextra -Werror 
MLX = -L$(LIB) -lmlx -framework OpenGL -framework AppKit 
SRCS = ft_printf/ft_printf.c \
	libft/ft_strncmp.c \
	ft_printf/ft_printf_utils.c \
	libft/ft_strnstr.c \
	get_next_line/get_next_line.c \
	src/game.c \
	get_next_line/get_next_line_utils.c \
	src/hooks.c \
	libft/ft_atoi.c \
	src/main.c \
	libft/ft_bzero.c \
	src/map_check_1.c \
	libft/ft_calloc.c \
	src/map_check_2.c \
	libft/ft_itoa.c \
	src/map_flood_fill.c \
	libft/ft_split.c \
	src/map_main_and_read.c \
	libft/ft_strlcat.c \
	src/player.c \
	libft/ft_strlcpy.c \
	src/render.c \
	libft/ft_strlen.c

OBJS = $(SRCS:.c=.o)

TARGET = so_long

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(MLX) -o $@ $^

%.o: %.c header.h libft/libft.h get_next_line/get_next_line.h ft_printf/ft_printf.h 
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
