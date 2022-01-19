DIRSRC		= ./srcs/

LIBFT		= ./libft/

NAMELFT		= ./libft/libft.a

SRC			= push_swap.c operators_1.c operators_2.c operators_3.c sort_short.c utils.c init.c\
				sort_big.c

SRCS		= $(addprefix ${DIRSRC}, ${SRC})

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

CC			= gcc
RM			= rm -f
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3

.c.o:
			${CC} ${CFLAGS} -c -I${LIBFT} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@make all -s -C ./libft
			${CC} ${CFLAGS} ${OBJS} ${NAMELFT} ${DYLIB} -o ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)
			@make fclean -s -C ./libft

re:			fclean all

.PHONY:		all clean fclean re