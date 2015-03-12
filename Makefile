# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/04 13:50:59 by jbahus            #+#    #+#              #
#    Updated: 2015/03/10 16:48:32 by jbahus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ft_error.c ft_ls.c get_name.c get_dir_param.c get_stats.c
SRC += ft_erase_lst.c aff_stats.c

DEL = rm -f

OBJ = $(SRC:.c=.o)

LIB_DIR = ./libft/

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@cd $(LIB_DIR); $(MAKE) -f Makefile
	@gcc $(FLAG) -c $(SRC)
	@gcc $(FLAG) -o $(NAME) $(OBJ) $(LIB_DIR)libft.a
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " | create |"
	@echo " |./ft_ls |"
	@echo " '--------'"

clean:
	@$(DEL) $(OBJ)

fclean: clean
	@$(DEL) $(NAME)
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " |./ft_ls |"
	@echo " | delete |"
	@echo " '--------'"

re: fclean all
