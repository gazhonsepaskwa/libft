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
SRCDIR = .
OBJDIR = build
INCDIR = .
# Library Name
NAME = libft.a

# Source and object files
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr.c\
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJS = build/ft_atoi.o build/ft_bzero.o build/ft_calloc.o build/ft_isalnum.o \
build/ft_isalpha.o build/ft_isascii.o build/ft_isdigit.o build/ft_isprint.o \
build/ft_itoa.o build/ft_memchr.o build/ft_memcmp.o build/ft_memcpy.o \
build/ft_memmove.o build/ft_memset.o build/ft_putchar_fd.o build/ft_putendl_fd.o \
build/ft_putnbr.o build/ft_putstr_fd.o build/ft_split.o build/ft_strchr.o \
build/ft_strdup.o build/ft_striteri.o build/ft_strjoin.o build/ft_strlcat.o \
build/ft_strlcpy.o build/ft_strlen.o build/ft_strmapi.o build/ft_strncmp.o \
build/ft_strnstr.o build/ft_strrchr.o build/ft_strtrim.o build/ft_substr.o \
build/ft_tolower.o build/ft_toupper.o

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