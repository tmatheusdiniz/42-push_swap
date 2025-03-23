# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 19:29:26 by mreinald          #+#    #+#              #
#    Updated: 2025/01/12 19:34:06 by mreinald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
MAGENTA	= \033[0;35m
CYAN	= \033[3;36m
RESET	= \033[0m

#Program's name
NAME		= bin/push_swap
BONUS_NAME	= bin/checker

# Commands/flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I ./include -I ./lib/Libft/include

# Directories
SRC_DIR		= srcs
OBJ_DIR		= objs
BIN_DIR		= bin
LIBFT_DIR	= ./lib/Libft/
BONUS_DIR   = bonus

# Find Sources code
SRCS		= $(wildcard $(SRC_DIR)/*/*.c)
OBJS		= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRCS:.c=.o))

# Bonus part
BONUS_SRCS	= $(wildcard $(BONUS_DIR)/*.c)
BONUS_OBJS	= $(patsubst $(BONUS_DIR)/%.c,$(OBJ_DIR)/bonus/%.o,$(BONUS_SRCS))
# Libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L./$(LIBFT_DIR) -lft

# ASCII Art
define ART
$(MAGENTA)
██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗ 
██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗
██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝
██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝ 
██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║     
╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝
  $(CYAN)━━━━━━━━━━━━━━━━━━━━━━━[$(RESET)Made by $(BLUE)@tmatheusdiniz$(CYAN)]━━━━━━━━━━━━━━━━━━━━━$(RESET)
endef
export ART

define BONUS_ART
$(MAGENTA)
 ██████╗██╗  ██╗███████╗ ██████╗██╗  ██╗███████╗██████╗ 
██╔════╝██║  ██║██╔════╝██╔════╝██║ ██╔╝██╔════╝██╔══██╗
██║     ███████║█████╗  ██║     █████╔╝ █████╗  ██████╔╝
██║     ██╔══██║██╔══╝  ██║     ██╔═██╗ ██╔══╝  ██╔══██╗
╚██████╗██║  ██║███████╗╚██████╗██║  ██╗███████╗██║  ██║
 ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝
  $(CYAN)━━━━━━━━━━━━━━━━━━━━━━━[$(RESET)Made by $(BLUE)@tmatheusdiniz$(CYAN)]━━━━━━━━━━━━━━━━━━━━━$(RESET)
endef
export BONUS_ART

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) $(LIBFT_FLAGS) -o $(NAME)
	@clear
	@echo "$$ART"
	@echo "$(CYAN)push_swap compiled successfully!$(RESET)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(INCLUDES) $(LIBFT_FLAGS) -o $(BONUS_NAME)
	@clear
	@echo "$$BONUS_ART"
	@echo "$(CYAN)checker compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@sleep 0.02
	@clear
	@echo "$(RED)Compiling push_swap sources $<$(RESET)"

$(OBJ_DIR)/bonus/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@sleep 0.02
	@clear
	@echo "$(RED)Compiling bonus file $<$(RESET)"

$(LIBFT):
	@make --silent -C $(LIBFT_DIR)

clean_bonus:
	@clear
	@echo "$(RED)Cleaning bonus program objects...$(RESET)"
	@rm -rf $(OBJ_DIR)/bonus
	@echo "$(GREEN)Bonus program objects cleaned!$(RESET)"

fclean_bonus: clean_bonus
	@clear
	@echo "$(RED)Removing bonus program binary...$(RESET)"
	@rm -rf $(BIN_DIR)/checker
	@echo "$(GREEN)Bonus program binary removed!$(RESET)"

clean:clean_bonus
	@clear
	@make --silent -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean fclean_bonus
	@clear
	@make --silent -C $(LIBFT_DIR) fclean
	@rm -rf $(BIN_DIR)

re: fclean all

re_bonus: fclean_bonus bonus

.PHONY: all clean fclean bonus re re_bonus
