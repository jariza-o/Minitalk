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

# Nombre que van a tener los programas
SERVER = server
CLIENT = client

# Flags para compilar y librerías
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft
PRINTF = ft_printf

# Flags para compilar este proyeto
FLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers -I$(LIBFT)/headers -L$(PRINTF) -lftprintf -L$(LIBFT) -lft

# Nombre de los Objs al compilar
SERVER_OBJS = server.o
CLIENT_OBJS = client.o

# Targets por defecto
all: $(SERVER) $(CLIENT)
	@echo "Minitalk está listo"

# Target para el bonus, que depende del target all
bonus: all

# Targets para construir el programa del server
$(SERVER) : $(SERVER_OBJS)
	# Compilar Libft
	@make -s -C $(LIBFT)
	# Compilar Ft_printf
	@make -s -C $(PRINTF)
	# Enlace de los ficheros Objs para crear el ejecutable del server
	@gcc $(FLAGS) $(SERVER_OBJS) -o $(SERVER)

# Targets para contruir el programa del client
$(CLIENT): $(CLIENT_OBJS)
	# Compilar Libft
	@make -s -C $(LIBFT)
	# Compilar Ft_printf
	@make -s -C $(PRINTF)
	# Enlace de los ficheros Objs para crear el ejecutable del server
	@gcc $(FLAGS) $(CLIENT_OBJS) -o $(CLIENT)

# Regla de patrones para crear archivos de objetos a partir del código fuente // ESTO QUE ES??
%.o: %.c
	# Compilar código fuente
	@gcc $(CFLAGS) -c $< -o $@

# Target para limpiar los objetos de compilación
clean:
	# Limpiar Libft
	@make fclean -s -C $(LIBFT)
	# Limpiar Ft_printf
	@make fclean -s -C $(PRINTF)
	# Limpiar ficheros Objs
	@rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	@echo "Los Objs han sido eliminados"

# Taget para limpiarlo todo
fclean: clean
	# Limpiar ejecutables
	@rm -f $(SERVER) $(CLIENT)
	@echo "Los ejecutables han sido eliminados"

# Target para reconstruir el proyecto
re: fclean all

#Taregt para reconstruir el proyecto con la parte bonus
rebonus: fclean all

.PHONY: all bonus clean fclean re rebonus