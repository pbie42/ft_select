# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbie <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 11:55:43 by pbie              #+#    #+#              #
#    Updated: 2016/05/19 14:54:01 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

CFLAGS = -g -Wall -Werror -Wextra -I includes

SRC = src/main.c \
			src/keys/arrows/arrow_down.c \
			src/keys/arrows/arrow_up.c \
			src/keys/arrows/arrows.c \
			src/keys/arrows/found.c \
			src/keys/delete_key.c \
			src/keys/enter_key.c \
			src/keys/keys.c \
			src/keys/search_key.c \
			src/keys/select_key.c \
			src/keys/space_key.c \
			src/keys/undo_key.c \
			src/list/ft_list_end.c \
			src/list/ft_list_free.c \
			src/list/ft_list_len.c \
			src/list/ft_list_remove.c \
			src/list/params.c \
			src/print/print.c \
			src/print/print_out.c \
			src/print/printcolor.c \
			src/print/printcolor_out.c \
			src/shell/environments.c \
			src/shell/ft_shell_free.c \
			src/shell/handlers.c \
			src/shell/shell.c \
			src/shell/signal.c \
			src/shell/view.c \
			src/utils/ft_putendnbr.c \
			src/utils/get_max.c \
			src/utils/path.c \
			src/utils/utils.c \
			src/utils/words_per_row.c \


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) -I libft/includes/libft.h libft/libft.a -ltermcap
	@echo "$(NAME) created"

clean :
	make -C libft clean
	rm -rf $(OBJ)
	@echo "OBJ deleted"

fclean : clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
	@echo "$(NAME) deleted"

re : fclean all

.PHONY: all clean fclean re
