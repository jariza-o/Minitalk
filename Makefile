# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 07:59:10 by jariza-o          #+#    #+#              #
#    Updated: 2023/02/28 07:59:10 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		minitalk.a

SRC = 		cliente.c servidor.c 

SRCBONUS =	cliente.c servidor_bonus.c

OBJT = 		$(SRC:.c=.o)

OBJTBONUS = $(SRCBONUS:.c=.o)

CFLAGS = 	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):
			gcc -c $(CFLAGS) $(SRC)
			ar rcs $(NAME) $(OBJT)

clean:
			rm -f $(OBJT) $(OBJTBONUS)

fclean: 	clean
			rm -f $(NAME)

bonus:
			gcc -c $(CFLAGS) $(SRCBONUS)
			ar rcs $(NAME) $(OBJTBONUS)

re: 		fclean all

.PHONY: all clean fclean bonus re