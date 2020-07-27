# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 19:35:02 by lcarmelo          #+#    #+#              #
#    Updated: 2020/03/14 16:53:49 by lcarmelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE_MINISHELL 	= \
					main \
					minishell \
					execute \
					commands

FILE_BUILTINS 	= \
				  	cmd_env \
				  	cmd_exit \
					cmd_pwd \
					cmd_cd \
					cmd_help

DIR_SRC			= ./src/
DIR_BUILT 		= ./src/builtins/
DIR_INC			= ./includes/
DIR_LIB			= ./libft/

SRC_MINISHELL 	= \
					$(addprefix $(DIR_SRC), $(addsuffix .c, $(FILE_MINISHELL))) \
					$(addprefix $(DIR_BUILT), $(addsuffix .c, $(FILE_BUILTINS)))

OBJ_MINISHELL 	= \
				  	$(addsuffix .o, $(FILE_MINISHELL)) \
				  	$(addsuffix .o, $(FILE_BUILTINS))

CC 	   			= gcc
MINISHELL 		= minishell
#CFLAGS 	   		= -Wall -Werror -Wextra -O2 -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)
CFLAGS 	   		=  -O2 -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)

all: minishell

lib:
	@make -C $(DIR_LIB)
	@cp libft/libft.a ./

obj:
	@$(CC) $(CFLAGS) -c $(SRC_MINISHELL)

minishell: lib obj
	@$(CC) $(CFLAGS) -o $(MINISHELL) $(OBJ_MINISHELL) libft/libft.a

clean:
	@make clean -C $(DIR_LIB)
	@rm -f $(OBJ_MINISHELL)
	@rm -f libft.a

fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(MINISHELL)

re: fclean all

compile: re
	@clear
	./$(MINISHELL)

.PHONY: all clean fclean re compile
