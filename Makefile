# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/23 12:34:35 by jbahus            #+#    #+#              #
#    Updated: 2015/12/03 04:04:40 by jbahus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC = main.c get_opt.c ft_new_lst.c ft_begin.c ft_error.c ft_write_files.c
SRC += ft_swap_error.c ft_ascii_sort.c ft_lst_del.c ft_time_sort.c get_stats.c
SRC += ft_ls.c ft_check_stats.c aff_stats.c aff_uid_grp.c aff_min_maj.c
SRC += ft_check_min_maj.c ft_ind_init.c ft_space_device.c little_check.c
SRC += ft_little_date.c ft_ind_stuff.c ft_main_do.c
HDR = ft_ls.h
LIB = -lft -L libft
OBJ = $(SRC:%.c=obj/%.o)
GCC = gcc -Wall -Wextra -Werror

all: lib_ft obj $(NAME)

lib_ft:
	@cd libft ; $(MAKE) -f Makefile

obj:
	@mkdir -p obj/

$(NAME): $(OBJ)
	@$(GCC) $(OBJ) -o $(NAME) $(LIB)

obj/%.o: %.c $(HDR)
	@$(GCC) -c $< -o $@

clean:
	@rm -rf obj/

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted."
	@make -C libft/ fclean

re: fclean all

norme:
	@norminette $(SRC) $(HDR)

.PHONY: all lib_ft clean fclean re norme