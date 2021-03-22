# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 16:56:02 by kefujiwa          #+#    #+#              #
#    Updated: 2021/03/23 02:04:48 by kefujiwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MAKEFILE ###

## COLORS ##

# Formats #
_RESET				= \x1b[0m
_BOLD				= \x1b[1m
_DIM				= \x1b[2m
_UNDER				= \x1b[4m
_BLINK				= \x1b[5m
_REV				= \x1b[7m
_HIDDEN				= \x1b[8m

# Foreground Colors #
_GREY				= \x1b[30m
_RED				= \x1b[31m
_GREEN				= \x1b[32m
_YELLOW				= \x1b[33m
_BLUE				= \x1b[34m
_PURPLE				= \x1b[35m
_CYAN				= \x1b[36m
_WHITE				= \x1b[37m

# Background Colors #
_BGREY				= \x1b[40m
_BRED				= \x1b[41m
_BGREEN				= \x1b[42m
_BYELLOW			= \x1b[43m
_BBLUE				= \x1b[44m
_BPURPLE			= \x1b[45m
_BCYAN				= \x1b[46m
_BWHITE				= \x1b[47m


# **************************************************************************** #

## VARIABLES ##

# Compilation #
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
AR					= ar rcs

# Delete #
RM					= rm -rf

# Directories #
HEADER_DIR			= includes/
SRCS_DIR			= srcs/
OBJS_DIR			= objs/
CONVERT_DIR			= convert/
PARSE_DIR			= parse/
UTILS_DIR			= utils/
LIBFT_DIR			= libft/

# Files #
CONVERT				= convert_c \
					  convert_contents \
					  convert_di \
					  convert_p \
					  convert_percent \
					  convert_s \
					  convert_u \
					  convert_x

PARSE				= get_conversion \
					  get_flag \
					  get_precision \
					  get_width \
					  parse_line

UTILS				= fill_zero \
					  ft_itoa_base \
					  ft_putchar_unit \
					  is_conversion \
					  str_toupper

SRCS				= ft_printf.c \
					  $(addprefix $(CONVERT_DIR), $(addsuffix .c, $(CONVERT))) \
					  $(addprefix $(PARSE_DIR), $(addsuffix .c, $(PARSE))) \
					  $(addprefix $(UTILS_DIR), $(addsuffix .c, $(UTILS)))

# Compiled Files #
OBJS				= $(SRCS:%.c=$(OBJS_DIR)%.o)
LIBFT_NAME			= $(LIBFT_DIR)libft.a
NAME				= libftprintf.a


# **************************************************************************** #

## RULES ##

# Main Rules #
all:				$(NAME)

clean:
					@$(MAKE) clean -C $(LIBFT_DIR)
					@echo "$(_RED)Cleaning libftprintf objects...\n$(_RESET)"
					@$(RM) $(OBJS_DIR)

fclean:				
					@$(MAKE) fclean -C $(LIBFT_DIR)
					@echo "$(_RED)Cleaning libftprintf objects...\n$(_RESET)"
					@$(RM) $(OBJS_DIR)
					@echo "$(_RED)Deleting library '$(NAME)'...\n$(_RESET)"
					@$(RM) $(NAME)

re:					fclean all

# Variable Rules #
$(NAME):			$(LIBFT_NAME) $(OBJS)
						@cp $(LIBFT_NAME) $(NAME)
						@$(AR) $(NAME) $(OBJS)
						@echo "\n\n$(_GREEN)Library '$(NAME)' compiled.\n$(_RESET)"
						@echo "Done !"

$(LIBFT_NAME):		FORCE
						@$(MAKE) -C $(LIBFT_DIR)

FORCE:

# Compiled Source Files #
$(OBJS):			$(OBJS_DIR)

$(OBJS_DIR)%.o: 	$(SRCS_DIR)%.c
						@printf "$(_YELLOW)Generating Libftprintf objects... %-33.33s\r$(_RESET)" $@
						@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

$(OBJS_DIR):
						@mkdir -p $(OBJS_DIR)
						@mkdir -p $(OBJS_DIR)$(CONVERT_DIR)
						@mkdir -p $(OBJS_DIR)$(PARSE_DIR)
						@mkdir -p $(OBJS_DIR)$(UTILS_DIR)

# Phony #
.PHONY:				all clean fclean re FORCE
