# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 19:25:33 by xlamiel-          #+#    #+#              #
#    Updated: 2025/08/01 21:29:56 by xlamiel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
# 📦 Project Configuration
###############################################################################

NAME		:= libft.a
SRC_DIR		:= src
OBJ_DIR		:= obj
DEP_DIR		:= dep
INCLUDE_DIR	:= include

###############################################################################
# 🛠️ Tools & Commands
###############################################################################

CC			:= gcc
AR			:= ar rcs
RM			:= rm -f
MKDIR		:= mkdir -p

###############################################################################
# ⚙️ Compilation Flags
###############################################################################

CFLAGS		:= -Wall -Wextra -Werror
DEPFLAGS	:= -MMD -MP
INCLUDES	:= -I$(INCLUDE_DIR)

###############################################################################
# 🎨 Terminal Colors
###############################################################################

GREEN		:= \033[0;32m
RED			:= \033[0;31m
RESET		:= \033[0m

###############################################################################
# 📄 Source Files
###############################################################################

SRC			:= \
	$(SRC_DIR)/ft_isalpha.c \
	$(SRC_DIR)/ft_isdigit.c \
	$(SRC_DIR)/ft_isalnum.c \
	$(SRC_DIR)/ft_isascii.c \
	$(SRC_DIR)/ft_isprint.c \
	$(SRC_DIR)/ft_isprint.c \
	$(SRC_DIR)/ft_isspace.c \
	$(SRC_DIR)/ft_strlen.c \
	$(SRC_DIR)/ft_memset.c \
	$(SRC_DIR)/ft_bzero.c \
	$(SRC_DIR)/ft_memcpy.c \
	$(SRC_DIR)/ft_memmove.c \
	$(SRC_DIR)/ft_strlcpy.c \
	$(SRC_DIR)/ft_strlcat.c \
	$(SRC_DIR)/ft_toupper.c \
	$(SRC_DIR)/ft_tolower.c \
	$(SRC_DIR)/ft_strchr.c \
	$(SRC_DIR)/ft_strrchr.c \
	$(SRC_DIR)/ft_strncmp.c \
	$(SRC_DIR)/ft_memchr.c \
	$(SRC_DIR)/ft_memcmp.c \
	$(SRC_DIR)/ft_strnstr.c \
	$(SRC_DIR)/ft_atoi.c \
	$(SRC_DIR)/ft_calloc.c \
	$(SRC_DIR)/ft_strdup.c \
	$(SRC_DIR)/ft_substr.c \
	$(SRC_DIR)/ft_strjoin.c \
	$(SRC_DIR)/ft_strtrim.c \
	$(SRC_DIR)/ft_split.c \
	$(SRC_DIR)/ft_itoa.c \
	$(SRC_DIR)/ft_itoa_base.c \
	$(SRC_DIR)/ft_strmapi.c \
	$(SRC_DIR)/ft_striteri.c \
	$(SRC_DIR)/ft_putchar_fd.c \
	$(SRC_DIR)/ft_putstr_fd.c \
	$(SRC_DIR)/ft_putendl_fd.c \
	$(SRC_DIR)/ft_putnbr_fd.c \
	$(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/ft_printf_char.c \
	$(SRC_DIR)/ft_printf_format.c \
	$(SRC_DIR)/ft_printf_number.c \
	$(SRC_DIR)/ft_printf_pointer.c \
	$(SRC_DIR)/ft_printf_string.c \
	$(SRC_DIR)/ft_printf_unsigned.c \
	$(SRC_DIR)/ft_satoi.c \
	$(SRC_DIR)/ft_satoi_core.c \
	$(SRC_DIR)/ft_satoi_utils.c \
	$(SRC_DIR)/ft_satol.c \
	$(SRC_DIR)/ft_satol_core.c \
	$(SRC_DIR)/ft_satol_utils.c 

###############################################################################
# 🔧 Derived File Lists
###############################################################################

OBJ			:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
DEPS		:= $(patsubst $(SRC_DIR)/%.c,$(DEP_DIR)/%.d,$(SRC))

###############################################################################
# 🚀 Build Targets
###############################################################################

all: | $(OBJ_DIR) $(DEP_DIR)
all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@echo "$(GREEN)✅ $@ Created$(RESET)"

###############################################################################
# 🧱 Object Compilation
###############################################################################

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@ -MF $(DEP_DIR)/$(notdir $*.d)

###############################################################################
# 📁 Directory Creation
###############################################################################

$(OBJ_DIR):
	@$(MKDIR) $@

$(DEP_DIR):
	@$(MKDIR) $@

###############################################################################
# 🧹 Cleaning Rules
###############################################################################

clean:
	@$(RM) -rf $(OBJ_DIR) $(DEP_DIR)
	@echo "$(RED)🧹 Build files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🧹 $(NAME) removed$(RESET)"

re: fclean all

###############################################################################
# 🐞 Debug Build
###############################################################################

debug:
	@$(MAKE) CFLAGS="$(CFLAGS) -g3" DEPFLAGS="$(DEPFLAGS)" re

# ============================================
# 🔍 Sección de depuración
#        make debug-vars     # Ver valores actuales de variables
#        make dry-run        # Ver qué se ejecutaría sin correrlo
#        make trace          # Ver trazas detalladas
#        make print-all      # Ver todo lo que Make conoce
#        make verbose        # Ver comandos reales ejecutados
# ============================================

# Regla para imprimir variables clave
debug-vars:
	@echo "🔧 Variables en uso:"
	@echo "CC		= $(CC)"
	@echo "CFLAGS	= $(CFLAGS)"
	@echo "SRC		= $(SRC)"
	@echo "OBJ		= $(OBJ)"
	@echo "TARGET  = $(TARGET)"
	@echo "LDFLAGS = $(LDFLAGS)"
	@echo "LDLIBS  = $(LDLIBS)"

# Regla para simular ejecución sin correr comandos
dry-run:
	@echo "🚫 Simulación de ejecución (dry-run):"
	@$(MAKE) -n

# Regla para mostrar trazas detalladas
trace:
	@echo "🧠 Trazas completas de ejecución:"
	@$(MAKE) -d

# Regla para mostrar todas las variables y reglas conocidas por Make
print-all:
	@echo "📜 Variables y reglas conocidas:"
	@$(MAKE) -p | less

# Regla para mostrar dependencias de un objetivo específico
deps:
	@echo "🔗 Dependencias de '$(TARGET)':"
	@$(MAKE) -n $(TARGET)

# Regla para mostrar comandos reales que se ejecutan
verbose:
	@echo "📣 Ejecución en modo verbose:"
	@$(MAKE) --no-print-directory VERBOSE=1

###############################################################################
# 📎 Dependency Inclusion
###############################################################################

-include $(wildcard $(DEPS))

###############################################################################
# 📌 Phony Targets
###############################################################################

.PHONY: all clean fclean re debug
