# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vim <vim@42urduliz.com>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 00:39:14 by vim               #+#    #+#              #
#    Updated: 2022/06/14 21:49:52 by vim              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINISH_MSG		= @echo "  \x1b[40m\x1b[38;2;16;19;33m\x1b[40m\x1b[01;37m     miniSH \x1b[0m\x1b[30m\x1b[0m\x1b[0;90m $(1)\x1b[0m"

MINISH_SRCS		= srcs/builtins/ft_env.c \
				  srcs/builtins/ft_export.c \
				  srcs/builtins/ft_unset.c \
				  srcs/builtins/ft_echo.c \
				  srcs/builtins/ft_exit.c \
				  srcs/builtins/ft_pwd.c \
				  srcs/builtins/ft_cd.c \
				  srcs/utils/strstop.c \
				  srcs/utils/strpush.c \
				  srcs/utils/manage_vars.c \
				  srcs/utils/validators.c \
				  srcs/utils/utils_vars.c \
				  srcs/pipes/piper.c \
				  srcs/signals/signals.c \
				  srcs/parser/redirects.c \
				  srcs/parser/iterator.c \
				  srcs/parser/variables.c \
				  srcs/parser/resolver.c \
				  srcs/parser/arguments.c \
				  srcs/parser/parser.c \
				  srcs/parser/splitter.c \
				  srcs/main.c
MINISH_TSRCS	= srcs/builtins/ft_env.c \
				  srcs/builtins/ft_export.c \
				  srcs/builtins/ft_unset.c \
				  srcs/builtins/ft_echo.c \
				  srcs/builtins/ft_exit.c \
				  srcs/builtins/ft_pwd.c \
				  srcs/builtins/ft_cd.c \
				  srcs/utils/strstop.c \
				  srcs/utils/strpush.c \
				  srcs/utils/manage_vars.c \
				  srcs/utils/validators.c \
				  srcs/utils/utils_vars.c \
				  srcs/pipes/piper.c \
				  srcs/signals/signals.c \
				  srcs/parser/redirects.c \
				  srcs/parser/iterator.c \
				  srcs/parser/variables.c \
				  srcs/parser/resolver.c \
				  srcs/parser/arguments.c \
				  srcs/parser/parser.c \
				  srcs/parser/splitter.c \
				  testers/main.c
MINISH_OBJS		= $(MINISH_SRCS:.c=.o)
MINISH_TOBJS	= $(MINISH_TSRCS:.c=.o)

MINISH_NAME		= miniSH

RL_INC			= /opt/homebrew/opt/readline/include
RL_LIB			= /opt/homebrew/opt/readline/lib

%.o : %.c
				@printf "  \x1b[40m\x1b[38;2;16;19;33m\x1b[40m\x1b[01;37m     miniSH \x1b[0m\x1b[30m\x1b[0m\x1b[0;90m Compiling \x1b[0;30m$@...                \x1b[0m\r"
				@clang -Wall -Werror -Wextra -Iincludes -Isrcs/libft/includes -I$(RL_INC) -O3 -c $< -o $@

$(MINISH_NAME):	depends $(MINISH_OBJS)
				@echo ""
				@clang $(MINISH_OBJS) -L. -lft -L$(RL_LIB) -lreadline -O3 -o ./$(MINISH_NAME)
				$(call MINISH_MSG,"Finished compiling project!")

test:			depends $(MINISH_TOBJS)
				@echo ""
				@clang $(MINISH_TOBJS) -L. -lft -L$(RL_LIB) -lreadline -O3 -fsanitize=address -o ./$(MINISH_NAME)
				$(call MINISH_MSG,"Finished compiling project!")

depends:
				$(call MINISH_MSG,"Attempting to compile required dependencies...")
				@(test ! -f ./libft.a && make -s -C srcs/libft LIBFT_OUT=$(PWD)) || true
				$(call MINISH_MSG,"Finished compiling dependencies")
				$(call MINISH_MSG,"Working on compiling miniSH...")

all:			$(MINISH_NAME)

clean:
				$(call MINISH_MSG,"Deleting dependencies")
				@rm -f $(MINISH_OBJS)
				@rm -f ./libft.a
				@make -C srcs/libft clean

fclean:			clean
				$(call MINISH_MSG,"Cleaning dependencies objects...")
				@make -s -C srcs/libft fclean
				$(call MINISH_MSG,"Deleting ./$(MINISH_NAME)...")
				@rm -f ./$(MINISH_NAME)


re:				fclean $(MINISH_NAME)


.PHONY:			depends all bonus clean fclean re 
