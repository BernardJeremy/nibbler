##
## Makefile<3> for Nibbler in /home/bernar_w/Projet/Nibbler/SDL/lib
## 
## Made by bernar_w
## Login   <bernar_w@epitech.net>
## 
## Started on  Sun Mar 16 21:41:01 2014 bernar_w
## Last update Sat Apr  5 15:22:51 2014 Claire Almozinos
##

SRC	= Error.cpp	\
	  NCurses.cpp

OBJ	= $(SRC:.cpp=.o)

NAME	= lib_nibbler_Ncurses.so

CC	= g++ -fPIC

RM	= rm -f

CXXFLAGS += -W -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) -shared $(SRC) -o $(NAME) -lncurses

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
