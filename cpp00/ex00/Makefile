# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 17:50:29 by seonjo            #+#    #+#              #
#    Updated: 2024/02/29 17:56:59 by seonjo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:=	cc
WFLAG		:=	-Wall -Wextra -Werror -std=c++98

DIR			:=	./
BASE		:=	megaphone.cpp
SRC			:= $(addprefix $(DIR), $(addsuffix .c, $(BASE)))
OBJ			:= $(addprefix $(DIR), $(addsuffix .o, $(BASE)))
NAME		:= megaphone

all : $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(WFLAG) $^ -o $@
	@echo "\033[32;1m\n🧊 [SUCCESS] $@ compiled successfully! ✨\033[m"

%.o : %.c
	@$(CC) $(WFLAG) -I. -c $< -o $@
	@echo "\033[34;1m🎲 [OK] $@ is compiled\033[m"

clean :
	@rm -f $(OBJ)
	@echo "\033[35;1m🧹 [CLEAN] Object files have been removed!\033[m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[35;1m🧹 [FCLEAN] Executable files have been fully removed!\033[m"

re : fclean all

.PHONY : all clean fclean re
