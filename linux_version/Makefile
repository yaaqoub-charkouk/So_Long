CC = cc
CFLAGS = -Wall -Wextra -Werror -I. 
MLX = -L. -lmlx_Linux -lmlx -lXext -lX11 -lm -lz

SRCS = ft_printf/ft_printf.c \
       ft_printf/ft_printf_utils.c \
       get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c \
       libft/ft_strncmp.c \
       libft/ft_strnstr.c \
       libft/ft_bzero.c \
       libft/ft_calloc.c \
       libft/ft_itoa.c \
       libft/ft_split.c \
       libft/ft_strlcat.c \
       libft/ft_strlcpy.c \
       libft/ft_strlen.c \

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
        bonus/enemy_1.c \
        bonus/enemy_2.c

OBJS = $(SRCS:.c=.o)
MOBJS = $(MANDATORY:.c=.o)
BOBJS = $(BONUS:.c=.o)

TARGET = so_long
TARGET_BNS = so_long_bonus

HEADERS = header.h libft/libft.h get_next_line/get_next_line.h ft_printf/ft_printf.h bonus/header_bonus.h

.PHONY: all clean fclean re bonus mandatory

all: $(TARGET) $(TARGET_BNS)

mandatory: $(TARGET)

bonus: $(TARGET_BNS)

$(TARGET): $(MOBJS) $(OBJS)
	@echo "Compiling $(TARGET)..."
	$(CC) $(CFLAGS) -o $@ $^ $(MLX)

$(TARGET_BNS): $(BOBJS) $(OBJS)
	@echo "Compiling $(TARGET_BNS)..."
	$(CC) $(CFLAGS) -o $@ $^ $(MLX)

%.o: %.c $(HEADERS)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS) $(MOBJS) $(BOBJS)

fclean: clean
	@echo "Removing binaries..."
	rm -f $(TARGET) $(TARGET_BNS)

re: fclean mandatory
