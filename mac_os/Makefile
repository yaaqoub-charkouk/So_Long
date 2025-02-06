CC = cc
LIB = /Users/ycharkou/
CFLAGS = -Wall -Wextra -Werror 
MLX = -L$(LIB) -lmlx -framework OpenGL -framework AppKit 
SRCS = ft_printf/ft_printf.c \
	ft_printf/ft_printf_utils.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	libft/ft_strncmp.c \
	libft/ft_strnstr.c \
	libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_itoa.c \
	libft/ft_split.c \
	libft/ft_strlcat.c \
	libft/ft_strlcpy.c \
	libft/ft_strlen.c
MANDATORY = src/hooks.c \
	src/main.c \
	src/map_check_1.c \
	src/map_check_2.c \
	src/map_flood_fill.c \
	src/map_main_and_read.c \
	src/player.c \
	src/render.c \
	src/game.c 
BONUS = bonus/hooks.c \
	bonus/main.c \
	bonus/map_check_1.c \
	bonus/map_check_2.c \
	bonus/map_flood_fill.c \
	bonus/map_main_and_read.c \
	bonus/player.c \
	bonus/render.c \
	bonus/game.c \
	bonus/enemy_test.c \
	bonus/enemy_1.c \

OBJS = $(SRCS:.c=.o)
MOBJS = $(MANDATORY:.c=.o)
BOBJS = $(BONUS:.c=.o)

TARGET = so_long
TARGET_BNS = so_long_bonus

HEADERS = header.h libft/libft.h get_next_line/get_next_line.h ft_printf/ft_printf.h bonus/header_bonus.h
.PHONY: all clean fclean re bonus mandatory

mandatory: $(TARGET)
bonus : $(TARGET_BNS)
all: $(TARGET) $(TARGET_BNS)

$(TARGET): $(MOBJS) $(OBJS)
	$(CC) $(CFLAGS) $(MLX) -o $@ $^

$(TARGET_BNS) : $(BOBJS) $(OBJS)
	$(CC) $(CFLAGS) $(MLX) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(MOBJS) $(BOBJS)

fclean: clean
	rm -f $(TARGET) $(TARGET_BNS)

re: fclean all
