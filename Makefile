NAME	= 	a.out

HEADER	= 	./srcs

SRCS	=	./main.cpp \
			./tests/utils.cpp \
			./tests/vector.cpp \
			./tests/stack.cpp \
			./tests/map.cpp \
			./tests/set.cpp
		
OBJS	= 	$(SRCS:.cpp=.o)

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -I

.cpp.o:
		clang++ $(CFLAGS) $(HEADER) -c $< -o $(<:.cpp=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
		clang++ $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re