# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/07 13:40:36 by dlerma-c          #+#    #+#              #
#    Updated: 2021/11/02 20:43:49 by dlerma-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#···································································#
#                               NAMES                               #
#···································································#
NAME = libft.a
#···································································#
#                                PATH                               #
#···································································#
LBFT_PATH = libft
GNL_PATH = gnl
OBJS_PATH = obj
#···································································#
#                               SRCS                                #
#···································································#
#LIBFT
SRCS_LBFT = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c\
		ft_memset.c ft_strchr.c ft_strdup.c ft_strjoin.c\
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c\
		ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c\
		ft_toupper.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_strmapi.c \
		ft_striteri.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c \
		ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c
#GET NEXT LINE
SRCS_GNL = get_next_line.c get_next_line_utils.c
#UNION
SRCS_NAME = $(addprefix $(LBFT_PATH)/, $(SRCS_LBFT)) \
		$(addprefix $(GNL_PATH)/, $(SRCS_GNL))
OBJS_NAME = $(SRCS_NAME:%.c=%.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME));
#···································································#
#                              FLAGS                                #
#···································································#
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
#if you make with dev, it will include fsanitize
DEV = 0
ifeq ($(DEV), 1)
	CFLAGS += -fsanitize=address
endif
#···································································#
#                              RULES                                #
#···································································#
.PHONY: all re clean fclean
all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS) 

$(OBJS_PATH)/%.o: $(LBFT_PATH)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ get_next_line.h libft.h

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH) 2> /dev/null
	
clean:
	rm -rf $(OBJS_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

