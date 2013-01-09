##
## Makefile for R-Type in /home/teisse_a//Documents/Tek3/RType/R-Type/Server
## 
## Made by alexandre teisseire
## Login   <teisse_a@epitech.net>
## 
## Started on  Wed Jan  9 09:55:44 2013 alexandre teisseire
## Last update Wed Jan  9 09:56:23 2013 alexandre teisseire
##

NAME		= R-Type

PATH_SRC	= "Room\ Management/src/"
PATH_INC	= "Room\ Management/includes"

SRC		= $(PATH_SRC)mainTestRoomManagement.cpp \
		  $(PATH_SRC)Account.cpp		\
		  $(PATH_SRC)GameplayEngine.cpp		\
		  $(PATH_SRC)Hall.cpp			\
		  $(PATH_SRC)Player.cpp			\
		  $(PATH_SRC)RegisterManager.cpp	\
		  $(PATH_SRC)Room.cpp			\
		  $(PATH_SRC)RoomManager.cpp		\
		  $(PATH_SRC)Scenario.cpp		\
		  $(PATH_SRC)Resources.cpp		\
		  $(PATH_SRC)TimePoint.cpp

OBJ		= $(SRC:.cpp=.o)

INCLUDES	= -I$(PATH_INC)

CXX		= g++

CXXFLAGS	= -Wall -Wextra -O3 -DNDEBUG $(INCLUDES) -std=c++0x

LDFLAGS		=

RM		= rm -rf
DUST		= *~ $(PATH_SRC)*~ $(PATH_INC)/*~

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ) $(DUST)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
