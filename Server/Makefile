##
## Makefile for R-Type in /home/teisse_a//Documents/Tek3/RType/R-Type/Server
## 
## Made by alexandre teisseire
## Login   <teisse_a@epitech.net>
## 
## Started on  Wed Jan  9 09:55:44 2013 alexandre teisseire
## Last update Sun Jan 13 00:27:57 2013 alexandre teisseire
##

NAME		= R-Type

PATH_SRC	= Room/sources/
PATH_SRC_REQ	= ../Generics/ReqServ/sources/
PATH_SRC_CL	= ../Generics/ReqCl/
PATH_SRC_LWP	= ../Generics/LWP/
PATH_SRC_NET	= ../Generics/Net/
PATH_SRC_NETW	= Network/sources/
PATH_SRC_ENT	= Entities/sources/
PATH_SRC_LOG	= ../Generics/Logger/

PATH_INC	= Room/include/
PATH_INC_REQ	= ../Generics/ReqServ/include/
PATH_INC_CL	= ../Generics/ReqCl/
PATH_INC_DL	= ../Generics/Dl/
PATH_INC_LWP	= ../Generics/LWP/
PATH_INC_NET	= ../Generics/Net/
PATH_INC_PC	= ../Generics/PC/
PATH_INC_PS	= ../Generics/PS/
PATH_INC_TP	= ../Generics/TP/
PATH_INC_NETW	= Network/include/
PATH_INC_ENT	= Entities/include/
PATH_INC_LOG	= ../Generics/Logger/

SRC		= $(PATH_SRC)Account.cpp		\
		  $(PATH_SRC)GameplayEngine.cpp		\
		  $(PATH_SRC)Hall.cpp			\
		  $(PATH_SRC)Player.cpp			\
		  $(PATH_SRC)RegisterManager.cpp	\
		  $(PATH_SRC)Room.cpp			\
		  $(PATH_SRC)RoomManager.cpp		\
		  $(PATH_SRC)Resources.cpp		

SRC_NET		= $(PATH_SRC_NET)EndPoint.cpp		\
		  $(PATH_SRC_NET)UnixSocketTcp.cpp	\
		  $(PATH_SRC_NET)UnixSocketUdp.cpp	

SRC_REQ		= $(PATH_SRC_REQ)CSRequest.cpp

SRC_CL		= $(PATH_SRC_CL)SCRequest.cpp

SRC_LWP		= $(PATH_SRC_LWP)ScopedLock.cpp		\
		  $(PATH_SRC_LWP)UnixCondVar.cpp	\
		  $(PATH_SRC_LWP)UnixMutex.cpp

SRC_ENT		= $(PATH_SRC_ENT)Scenario.cpp		\
		  Main.cpp

SRC_LOG		= $(PATH_SRC_LOG)logger.cpp

SRC_NETW	= $(PATH_SRC_NETW)ClientService.cpp	\
		  $(PATH_SRC_NETW)NetworkManager.cpp	\
		  $(PATH_SRC_NETW)PackMan.cpp		\
		  $(PATH_SRC_NETW)ServerService.cpp

OBJ		= $(SRC:.cpp=.o)
OBJ_REQ		= $(SRC_REQ:.cpp=.o)
OBJ_CL		= $(SRC_CL:.cpp=.o)
OBJ_LWP		= $(SRC_LWP:.cpp=.o)
OBJ_NETW	= $(SRC_NETW:.cpp=.o)
OBJ_ENT		= $(SRC_ENT:.cpp=.o)
OBJ_LOG		= $(SRC_LOG:.cpp=.o)
OBJ_NET		= $(SRC_NET:.cpp=.o)

INCLUDES	= -I$(PATH_INC) 	\
		  -I$(PATH_INC_REQ) 	\
		  -I$(PATH_INC_CL) 	\
		  -I$(PATH_INC_DL)	\
		  -I$(PATH_INC_LWP)	\
		  -I$(PATH_INC_NET)	\
		  -I$(PATH_INC_PC)	\
		  -I$(PATH_INC_PS)	\
		  -I$(PATH_INC_TP)	\
		  -I$(PATH_INC_ENT)	\
		  -I$(PATH_INC_LOG)	\
		  -I$(PATH_INC_NETW)

CXX		= g++

CXXFLAGS	= -Wall -Wextra -O3 -DNDEBUG $(INCLUDES) -std=c++0x -g3

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
		  $(PATH_INC_LOG)*~

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_REQ) $(OBJ_CL) $(OBJ_LWP) $(OBJ_NETW) $(OBJ_ENT) $(OBJ_NET) $(OBJ_LOG)
		$(CXX) -o $(NAME) $(OBJ) $(OBJ_REQ) $(OBJ_CL) $(OBJ_LWP) $(OBJ_NETW) $(OBJ_ENT) $(OBJ_NET) $(OBJ_LOG) $(LDFLAGS)

clean:
		$(RM) $(OBJ) $(OBJ_REQ) $(OBJ_CL) $(OBJ_LWP) $(OBJ_NETW) $(OBJ_ENT) $(OBJ_NET) $(DUST)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
