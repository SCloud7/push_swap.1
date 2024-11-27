NAME = push_swap
CC = gcc 
HEAD = .
CFLAGS = -g3 -Wall -Wextra -Werror
SOURCES = main.c errors_verif.c utils.c lst_init.c init_a_to_b.c init_b_to_a.c commands.c sorts.c
		        
OBJECTS = $(SOURCES:.c=.o)

MAKE_LIBFT        =    make -s -C ./lib
LIBFT_A			=		./lib/libft.a

all: ${NAME}

$(NAME): $(OBJECTS)
	$(MAKE_LIBFT)
	${CC} ${CFLAGS} ${OBJECTS} ${LIBFT_A} -o ${NAME}
	
$(OBJECTS): $(SOURCES) 


.c.o:
	$(CC) $(CFLAGS)  -c $< -o $@ -I $(HEAD)

clean	:
	rm -rf $(OBJECTS)

fclean :	clean
	rm -rf $(NAME)

re :	fclean all

.PHONY:	all	clean	fclean	re