# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 19:35:02 by lcarmelo          #+#    #+#              #
#    Updated: 2020/09/02 15:46:35 by lcarmelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE_MINISHELL 	= \
					minishell \
					commands \
					prompt \
					parser \
					process \
					utilities \
					env

FILE_BUILTINS 	= \
				  	cmd_env \
				  	cmd_exit \
					cmd_pwd \
					cmd_cd \
					cmd_help \
					cmd_clear \
					cmd_echo \
					cmd_setenv \
					cmd_eval

DIR_SRC			= ./src/
DIR_BUILT 		= ./src/builtins/
DIR_INC			= ./includes/
DIR_LIB			= ./libft/
DIR_OBJ 		= ./obj/

OBJ_MINISHELL 	= \
				  	$(addprefix $(DIR_OBJ), $(addsuffix .o, $(FILE_MINISHELL))) \
				  	$(addprefix $(DIR_OBJ), $(addsuffix .o, $(FILE_BUILTINS))) \


CC 	   			= gcc
MINISHELL 		= minishell
#CFLAGS 	   		= -Wall -Werror -Wextra -O2 -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)
CFLAGS 	   		=  -O2 -g -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)

all: minishell

lib:
	@make -C $(DIR_LIB)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

minishell: $(DIR_OBJ) $(OBJ_MINISHELL) lib 
	@$(CC) $(CFLAGS) -o $(MINISHELL) $(OBJ_MINISHELL) $(DIR_LIB)libft.a

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
 
$(DIR_OBJ)%.o: $(DIR_BUILT)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	@make clean -C $(DIR_LIB)
	@rm -rf $(DIR_OBJ)

fclean: clean
	@rm -rf $(MINISHELL)

re: fclean all

.PHONY: all clean fclean re
