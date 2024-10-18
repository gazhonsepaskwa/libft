# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalebrun <nalebrun@student.s19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 14:22:51 by nalebrun          #+#    #+#              #
#    Updated: 2024/10/15 17:00:33 by nalebrun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories
SRCDIR = srcs
OBJDIR = build
INCDIR = includes
# Library Name
NAME = libft.a

# Source and object files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Phony targets
.PHONY: all clean fclean re

# Default target
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "Library $(NAME) created."

# Rule to create object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Create object directory if not exists
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Clean object files
clean:
	@rm -rf $(OBJDIR)
	@echo "Object files removed."

# Full clean (object files and library)
fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned all generated files."

# Rebuild everything
re: fclean all