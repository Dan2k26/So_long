#···································································#
#                               NAMES                               #
#···································································#
NAME = so_long
#···································································#
#                                PATH                               #
#···································································#
OBJ_PATH = obj
SRC_PATH = src
INC_PATH = inc
#···································································#
#                               SRCS                                 #
#···································································#
SRCS = main.c check_errors.c
OBJS_NAME = $(SRCS:%.c=%.o)
OBJS = $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))
#···································································#
#                              FLAGS                                #
#···································································#
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
#include <xx.h> // path of .h
CFLAGS += -I $(INC_PATH)
#if you make with dev, it will include fsanitize
DEV = N
ifeq ($(DEV), Y)
	CFLAGS += -fsanitize=address
endif
#···································································#
#                              RULES                                #
#···································································#
.PHONY: all re clean fclean
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJS): | $(OBJ_PATH)

$(OBJ_PATH): 
	mkdir -p $(OBJ_PATH) 2> /dev/null

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all
