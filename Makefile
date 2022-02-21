SRCS	= ft_printf.c ft_printmemory.c ft_printhexa.c ft_printstrchar.c ft_printnumber.c ft_printunsigned.c \
		ft_utils.c ft_lens.c ft_checkflags.c

OBJS	= ${SRCS:.c=.o}

SRCSB	= ft_printf.c ft_printmemory.c ft_printhexa.c ft_printstrchar.c ft_printnumber.c ft_printunsigned.c \
		ft_utils.c ft_lens.c ft_checkflags.c

OBJB	= ${SRCSB:.c=.o}

NAME	= libftprintf.a

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

AR = ar rc

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${AR} ${NAME} ${OBJS}
				ranlib ${NAME}

bonus:		all ${OBJB}
				@make OBJS="${OBJB}"

all:		${NAME}

clean:
				${RM} ${OBJS} ${OBJB}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

rebonus:	fclean bonus

.PHONY:		all bonus clean fclean re rebonus
