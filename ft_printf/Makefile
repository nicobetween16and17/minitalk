SRCS		=	ft_utils.c\
				ft_printf.c\
				ft_printhex.c\
				ft_print_ptr.c\

NAME		=	libftprintf.a

CFLAGS		=	-Wall -Werror -Wextra

CC			=	gcc

RM			=	rm -f

ARRCS		=	ar rcs

INCS		=	ft_printf.h

OBJS		=	${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME}: ${OBJS}
		${ARRCS} ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
