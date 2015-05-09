NAME = dungeonfinal
TARBALL = mcolozzo-$(NAME).tar.gz
SRC = main.cpp am.cpp room.cpp traverse.cpp pizzadelivery.cpp swap.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -f

CXXFLAGS = -g

all: $(OBJ)
	g++ -g $(OBJ) -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(NAME)

re: fclean all

submit: fclean
	tar cvzf $(TARBALL) *


