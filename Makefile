# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 11:46:32 by matle-br          #+#    #+#              #
#    Updated: 2024/07/11 16:44:31 by matle-br         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

CC = cc
FLAGS = -Wall -Wextra -Werror -g
GREEN = \033[32m
YELLOW = \033[33m
ROUGE = \033[1;31m

LIBFT_A = ./includes/libft/libft.a
CLIENT = src/client.c
SERVER = src/server.c

RM = rm -f

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(LIBFT_A) $(CLIENT)
		@$(CC) $(CLIENT) $(LIBFT_A) $(FLAGS) -o $(NAME_CLIENT)

$(NAME_SERVER) : $(LIBFT_A) $(SERVER)
		@$(CC) $(SERVER) $(LIBFT_A) $(FLAGS) -o $(NAME_SERVER)


	@echo  "$(GREEN)███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░░██╗"
	@echo  "$(GREEN)████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝"
	@echo  "$(GREEN)██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝░"
	@echo  "$(GREEN)██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░"
	@echo  "$(GREEN)██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██╗"
	@echo  "$(GREEN)╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝"
	@echo  "$(GREEN)"
	@echo  "$(GREEN)░█████╗░░█████╗░███╗░░░███╗██████╗░██╗██╗░░░░░███████╗██████╗░"
	@echo  "$(GREEN)██╔══██╗██╔══██╗████╗░████║██╔══██╗██║██║░░░░░██╔════╝██╔══██╗"
	@echo  "$(GREEN)██║░░╚═╝██║░░██║██╔████╔██║██████╔╝██║██║░░░░░█████╗░░██║░░██║"
	@echo  "$(GREEN)██║░░██╗██║░░██║██║╚██╔╝██║██╔═══╝░██║██║░░░░░██╔══╝░░██║░░██║"
	@echo  "$(GREEN)╚█████╔╝╚█████╔╝██║░╚═╝░██║██║░░░░░██║███████╗███████╗██████╔╝"
	@echo  "$(GREEN)░╚════╝░░╚════╝░╚═╝░░░░░╚═╝╚═╝░░░░░╚═╝╚══════╝╚══════╝╚═════╝░"

$(LIBFT_A) :
	@echo "$(YELLOW)Libft is compiling..."
	@make bonus --no-print-directory -C ./includes/libft

clean :
	@$(RM) $(OBJS)
	@make clean --no-print-directory -C ./includes/libft

fclean : clean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@make fclean --no-print-directory -C ./includes/libft
	@echo "$(ROUGE)Fclean is running..."

re : fclean all

.PHONY: all clean fclean re
