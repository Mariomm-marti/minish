# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vim <vim@42urduliz.com>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 00:39:14 by vim               #+#    #+#              #
#    Updated: 2022/04/08 13:51:19 by vim              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINISH_MSG		= @echo "  \x1b[40m\x1b[38;2;16;19;33m\x1b[40m\x1b[01;37m     miniSH \x1b[0m\x1b[30m\x1b[0m\x1b[0;90m $(1)\x1b[0m"

MINISH_SRCS		= $(wildcard srcs/*/*.c srcs/*.c)
MINISH_OBJS		= $(MINISH_SRCS:.c=.o)

MINISH_NAME		= miniSH

%.o : %.c
				@printf "  \x1b[40m\x1b[38;2;16;19;33m\x1b[40m\x1b[01;37m     miniSH \x1b[0m\x1b[30m\x1b[0m\x1b[0;90m Compiling \x1b[0;30m$@...                \x1b[0m\r"
				@clang -Wall -Werror -Wextra -Iincludes -Isrcs/libft/includes -c $< -o $@ -O3

$(MINISH_NAME):	depends $(MINISH_OBJS)
				@echo ""
				@clang $(MINISH_OBJS) -L. -lft -lreadline -o ./$(MINISH_NAME) -O3
				$(call MINISH_MSG,"Finished compiling project!")

depends:
				$(call MINISH_MSG,"Attempting to compile required dependencies...")
				@(test ! -f ./libft.a && make -s -C srcs/libft LIBFT_OUT=$(PWD)) || true
				$(call MINISH_MSG,"Finished compiling dependencies")
				$(call MINISH_MSG,"Working on compiling miniRT...")

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
