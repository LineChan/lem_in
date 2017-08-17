NAME			:= lem-in

all : $(NAME)

$(NAME) :
	make -C libs

clean :
	make -C libs clean

fclean :
	make -C libs fclean

re : fclean all

.SILENT:
