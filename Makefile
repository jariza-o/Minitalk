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

# Flags for compile the libreys
CFLAGS = gcc -Wall -Werror -Wextra
LIBFT = libft/
PRINTF = ft_printf/

# Default Targets
all:
	@make -C ${LIBFT}
	@make -C ${PRINTF}
	@${CFLAGS} libft/libft.a ft_printf/libftprintf.a server.c -o server
	@${CFLAGS} libft/libft.a ft_printf/libftprintf.a client.c -o client
	@echo "Minitalk está listo"

# Bonus Taregt
bonus: all

# Clean Targets
clean:
	# Limpiar Libft
	@make fclean -s -C $(LIBFT)
	# Limpiar Ft_printf
	@make fclean -s -C $(PRINTF)
	# Limpiar ficheros Objs
	@echo "Los Objs han sido eliminados"

# FClean Target
fclean: clean
	# Limpiar ejecutables
	@rm -f server client
	@echo "Los ejecutables han sido eliminados"

# Rebuild Target
re: fclean all

.PHONY: all bonus clean fclean re