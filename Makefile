# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/15 12:38:32 by mmthethw          #+#    #+#              #
#    Updated: 2017/09/18 10:12:19 by mmthethw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS_PATH = srcs/

OBJ_PATH  = obj/

LIBFT_PATH = libft/

FLAGS = -Wall -Werror -Wextra

INC = -I ./includes/ -I ./$(LIBFT_PATH)includes/

SRCS_NAME =	ft_ls.c \
			ft_add_file.c \
			ft_display_all.c \
			ft_display_detailed_list.c \
			ft_display_iterms.c \
			ft_display_list.c \
			ft_swap.c \
	    	ft_parsing.c \
			ft_sort_list.c 	

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJ) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME)
	@echo "\033[32m\033[1;32m$(NAME)\033[1;0m\033[32m Successfully created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@

clean:
	@make -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31m\033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
