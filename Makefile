# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 14:22:51 by nalebrun          #+#    #+#              #
#    Updated: 2024/11/27 12:57:42 by nalebrun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories
SRCDIR = srcs
OBJDIR = obj
INCDIR = .

# Library Name
NAME = libft.a

# Source and object files
SRCS = $(shell find $(SRCDIR) -name "*.c")
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

.PHONY: all clean fclean re

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "Library $(NAME) created."

# obj
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:
	@rm -rf $(OBJDIR)
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned all generated files."

re: fclean all
