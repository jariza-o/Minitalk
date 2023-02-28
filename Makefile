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

SERVER = 		server.a
CLIENTE = 		cliente.a

SRC = 		cliente.c servidor.c 

# SRCBONUS =	cliente.c servidor_bonus.c

SERVER_OBJS = server.o
CLIENTE_OBJS = cliente.o

# LIBRERIAS
PRINTF = Ft_printf
LIBFT = Libft

# OBJTBONUS = $(SRCBONUS:.c=.o)

CFLAGS = 	-Wall -Werror -Wextra -I$(PRINTF)/headers -I$(LIBFT)/headers -L$(PRINTF) -lftprintf -L$(LIBFT) -lft

all:		$(SERVER) $(CLIENTE)
	@echo "Minital esta listo"

$(NAME):
			gcc -c $(CFLAGS) $(SRC)
			ar rcs $(NAME) $(OBJT)

clean:
			rm -f $(OBJT) $(OBJTBONUS)

fclean: 	clean
			rm -f $(NAME)

# bonus:
# 			gcc -c $(CFLAGS) $(SRCBONUS)
# 			ar rcs $(NAME) $(OBJTBONUS)

re: 		fclean all

.PHONY: all clean fclean bonus re