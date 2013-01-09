##
## Makefile for R-Type in /home/teisse_a//Documents/Tek3/RType/R-Type/Server
## 
## Made by alexandre teisseire
## Login   <teisse_a@epitech.net>
## 
## Started on  Wed Jan  9 09:55:44 2013 alexandre teisseire
## Last update Wed Jan  9 11:02:47 2013 alexandre teisseire
##

NAME		= R-Type

PATH_SRC	= Room_Management/src/
PATH_SRCREQ	= ../Generics/ReqServ/sources/
PATH_SRCNET	= NetWork/sources

PATH_INC	= Room_Management/includes
PATH_INCREQ	= ../Generics/ReqServ/include/
PATH_INCNET	= NetWork/include/

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

SRCREQ		= $(PATH_SRCREQ)CSRequest.cpp


OBJ		= $(SRC:.cpp=.o)
OBJREQ		= $(SRCREQ:.cpp=.o)

INCLUDES	= -I$(PATH_INC) -I$(PATH_INCREQ) -I$(PATH_INCNET)

CXX		= g++

CXXFLAGS	= -Wall -Wextra -O3 -DNDEBUG $(INCLUDES) -std=c++0x

LDFLAGS		=

RM		= rm -rf
DUST		= *~ $(PATH_SRC)*~ $(PATH_INC)/*~

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJREQ)
		$(CXX) -o $(NAME) $(OBJ) $(OBJREQ) $(LDFLAGS)

clean:
		$(RM) $(OBJ) $(DUST)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
