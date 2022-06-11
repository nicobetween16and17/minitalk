all:
	gcc -Wall -Werror -Wextra server.c Libft/libft.a ft_printf/libftprintf.a -o server && gcc -Wall -Werror -Wextra client.c Libft/libft.a -o client && ./server
clean:
	rm client server