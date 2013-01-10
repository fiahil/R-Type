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
PATH_SRC_REQ	= ../Generics/ReqServ/sources/
PATH_SRC_LWP	= ../Generics/LWP/
PATH_SRC_NETW	= NetWork/sources/

PATH_INC	= Room_Management/includes/
PATH_INC_REQ	= ../Generics/ReqServ/include/
PATH_INC_DL	= ../Generics/Dl/
PATH_INC_LWP	= ../Generics/LWP/
PATH_INC_NET	= ../Generics/Net/
PATH_INC_PC	= ../Generics/PC/
PATH_INC_PS	= ../Generics/PS/
PATH_INC_TP	= ../Generics/TP/
PATH_INC_NETW	= NetWork/include/

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

SRC_REQ		= $(PATH_SRC_REQ)CSRequest.cpp

SRC_LWP		= $(PATH_SRC_LWP)ScopedLock.cpp		\
		  $(PATH_SRC_LWP)UnixCondVar.cpp	\
		  $(PATH_SRC_LWP)UnixMutex.cpp

OBJ		= $(SRC:.cpp=.o)
OBJ_REQ		= $(SRC_REQ:.cpp=.o)
OBJ_LWP		= $(SRC_LWP:.cpp=.o)
OBJ_NETW	= $(SRC_NETW:.cpp=.o)

INCLUDES	= -I$(PATH_INC) 	\
		  -I$(PATH_INC_REQ) 	\
		  -I$(PATH_INC_DL)	\
		  -I$(PATH_INC_LWP)	\
		  -I$(PATH_INC_NET)	\
		  -I$(PATH_INC_PC)	\
		  -I$(PATH_INC_PS)	\
		  -I$(PATH_INC_TP)	\
		  -I$(PATH_INC_NETW)

CXX		= g++

CXXFLAGS	= -Wall -Wextra -O3 -DNDEBUG $(INCLUDES) -std=c++0x

LDFLAGS		= -lpthread

RM		= rm -rf
DUST		= *~ 			\
		  $(PATH_SRC)*~ 	\
		  $(PATH_SRC_REQ)*~	\
		  $(PATH_SRC_LWP)*~	\
		  $(PATH_SRC_NET)*~	\
		  $(PATH_INC)*~		\
		  $(PATH_INC_REQ)*~	\
		  $(PATH_INC_DL)*~	\
		  $(PATH_INC_LWP)*~	\
		  $(PATH_INC_NET)*~	\
		  $(PATH_INC_PC)*~	\
		  $(PATH_INC_PS)*~	\
		  $(PATH_INC_TP)*~	\
		  $(PATH_INC_NETW)*~	\

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_REQ) $(OBJ_LWP)
		$(CXX) -o $(NAME) $(OBJ) $(OBJ_REQ) $(OBJ_LWP) $(LDFLAGS)

clean:
		$(RM) $(OBJ) $(DUST)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
