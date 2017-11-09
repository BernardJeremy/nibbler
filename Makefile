##
## Makefile for abstact in /home/bernar_w/Projet/AbstractVM
## 
## Made by bernar_w
## Login   <bernar_w@epitech.net>
## 
## Started on  Fri Feb 28 13:09:06 2014 bernar_w
## Last update Sat Apr  5 16:22:26 2014 Jeremy Bernard
##

SRC	= main.cpp	\
	  Error.cpp	\
	  Snake.cpp	\
	  Fruit.cpp	\
	  Game.cpp	\
	  Lib.cpp	\
	  Init.cpp	\
	  Action.cpp	\
	  Score.cpp

OBJ	= $(SRC:.cpp=.o)

NAME	= nibbler

CC	= g++ -fPIC -export-dynamic

RM	= rm -f

CXXFLAGS += -W -Wall -Wextra -Werror

WAYSDL=		cd ./SDL
WAYALLEGRO=	cd ./Allegro
WAYNCURSES=	cd ./NCurses

NAMESDL		= lib_nibbler_SDL.so
NAMENCURSES	= lib_nibbler_Ncurses.so
NAMEALLEGRO	= lib_nibbler_Allegro.so

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME) -ldl
	$(WAYSDL) ; make ; mv $(NAMESDL) ..
	$(WAYALLEGRO) ; make ; mv $(NAMEALLEGRO) ..
##	$(WAYNCURSES) ; make ; mv $(NAMENCURSES) ..

clean:
	$(RM) $(OBJ)
	$(WAYSDL) ; make clean
	$(WAYALLEGRO) ; make clean
##	$(WAYNCURSES) ; make clean

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAMESDL)
	$(RM) $(NAMEALLEGRO)
	$(RM) $(NAMENCURSES)
	$(WAYSDL) ; make fclean
	$(WAYALLEGRO) ; make fclean
##	$(WAYNCURSES) ; make fclean

re:	fclean all

.PHONY: all clean fclean re
