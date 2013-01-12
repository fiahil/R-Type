##
## Makefile for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
##
## Made by vincent lemonnier
## Login   <lemonn_v@epitech.net>
##
## Started on  Mon Apr 23 18:20:16 2012 vincent lemonnier
##

NAME		= RT_testentity

SRC		= src/mainTestEntities.cpp \
		  src/Scenario.cpp \
		  src/TestMob.cpp

OBJ		= $(SRC:.cpp=.o)

INCLUDES	= -I./includes/

CXX		= g++

CXXFLAGS	= -Wall -Wextra -O3 -DNDEBUG $(INCLUDES)

LDFLAGS		=

RM		= rm -rf
DUST		= *~ src/*~ includes/*~

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ) $(DUST)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
