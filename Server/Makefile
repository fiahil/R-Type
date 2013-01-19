##
## Makefile for R-Type in /home/teisse_a//Documents/Tek3/RType/R-Type/Server
## 
## Made by alexandre teisseire
## Login   <teisse_a@epitech.net>
## 
## Started on  Wed Jan  9 09:55:44 2013 alexandre teisseire
## Last update Thu Jan 17 17:51:33 2013 alexandre teisseire
##

NAME		= R-Type

PATH_SRC	= Room/sources/
PATH_SRC_REQ	= ../Generics/ReqServ/sources/
PATH_SRC_LWP	= ../Generics/LWP/
PATH_SRC_NET	= ../Generics/Net/
PATH_SRC_NETW	= Network/sources/
PATH_SRC_LOG	= ../Generics/Logger/
PATH_SRC_QTREE	= ./Quadtree/sources/
PATH_SRC_GPLAY	= ./Gameplay/sources/

PATH_INC	= Room/include/
PATH_INC_REQ	= ../Generics/ReqServ/include/
PATH_INC_DL	= ../Generics/Dl/
PATH_INC_CMD	= ../Generics/Cmd/
PATH_INC_LWP	= ../Generics/LWP/
PATH_INC_NET	= ../Generics/Net/
PATH_INC_PC	= ../Generics/PC/
PATH_INC_PS	= ../Generics/PS/
PATH_INC_TP	= ../Generics/TP/
PATH_INC_NETW	= Network/include/
PATH_INC_LOG	= ../Generics/Logger/
PATH_INC_QTREE	= Quadtree/include/
PATH_INC_GPLAY	= Gameplay/include/

SRC		= $(PATH_SRC)Account.cpp		\
		  $(PATH_SRC)GameplayEngine.cpp		\
		  $(PATH_SRC)Hall.cpp			\
		  $(PATH_SRC)Player.cpp			\
		  $(PATH_SRC)RegisterManager.cpp	\
		  $(PATH_SRC)Room.cpp			\
		  $(PATH_SRC)RoomManager.cpp		\
		  $(PATH_SRC)Resources.cpp		\
		  Main.cpp

SRC_NET		= $(PATH_SRC_NET)EndPoint.cpp		\
		  $(PATH_SRC_NET)UnixSocketTcp.cpp	\
		  $(PATH_SRC_NET)UnixSocketUdp.cpp

SRC_REQ		= $(PATH_SRC_REQ)CSRequest.cpp		\
		  $(PATH_SRC_REQ)SCRequest.cpp

SRC_LWP		= $(PATH_SRC_LWP)ScopedLock.cpp		\
		  $(PATH_SRC_LWP)UnixCondVar.cpp	\
		  $(PATH_SRC_LWP)UnixMutex.cpp

SRC_LOG		= $(PATH_SRC_LOG)logger.cpp

SRC_GPLAY	= $(PATH_SRC_GPLAY)GameplayEngine.cpp

SRC_NETW	= $(PATH_SRC_NETW)ClientService.cpp	\
		  $(PATH_SRC_NETW)NetworkManager.cpp	\
		  $(PATH_SRC_NETW)PackMan.cpp		\
		  $(PATH_SRC_NETW)PackManUDP.cpp	\
		  $(PATH_SRC_NETW)ServerService.cpp	\
		  $(PATH_SRC_NETW)ClientServiceWorker.cpp \
		  $(PATH_SRC_NETW)ClientServiceUDPWorker.cpp

SRC_QTREE	= $(PATH_SRC_QTREE)Collider.cpp		\
		  $(PATH_SRC_QTREE)Node.cpp		\
		  $(PATH_SRC_QTREE)QuadTree.cpp


OBJ		= $(SRC:.cpp=.o)
OBJ_REQ		= $(SRC_REQ:.cpp=.o)
OBJ_CL		= $(SRC_CL:.cpp=.o)
OBJ_LWP		= $(SRC_LWP:.cpp=.o)
OBJ_NETW	= $(SRC_NETW:.cpp=.o)
OBJ_LOG		= $(SRC_LOG:.cpp=.o)
OBJ_NET		= $(SRC_NET:.cpp=.o)
OBJ_QTREE	= $(SRC_QTREE:.cpp=.o)

INCLUDES	= -I$(PATH_INC) 	\
		  -I$(PATH_INC_REQ) 	\
		  -I$(PATH_INC_CL) 	\
		  -I$(PATH_INC_DL)	\
		  -I$(PATH_INC_CMD)	\
		  -I$(PATH_INC_LWP)	\
		  -I$(PATH_INC_NET)	\
		  -I$(PATH_INC_PC)	\
		  -I$(PATH_INC_PS)	\
		  -I$(PATH_INC_TP)	\
		  -I$(PATH_INC_LOG)	\
		  -I$(PATH_INC_NETW)	\
		  -I$(PATH_INC_GPLAY)	\
		  -I$(PATH_INC_QTREE)

CXX		= g++

CXXFLAGS	= -Wall -Wextra -O3 $(INCLUDES) -std=c++0x -g3

LDFLAGS		= -lpthread

RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_REQ) $(OBJ_CL) $(OBJ_LWP) $(OBJ_NETW) $(OBJ_NET) $(OBJ_LOG) $(OBJ_QTREE) $(OBJ_GPLAY)
		$(CXX) -o $(NAME) $(OBJ) $(OBJ_REQ) $(OBJ_CL) $(OBJ_LWP) $(OBJ_NETW) $(OBJ_NET) $(OBJ_LOG) $(OBJ_QTREE) $(OBJ_GPLAY) $(LDFLAGS)

clean:
		$(RM) $(OBJ) $(OBJ_REQ) $(OBJ_CL) $(OBJ_LWP) $(OBJ_NETW) $(OBJ_NET) $(OBJ_LOG) $(OBJ_QTREE) $(OBJ_GPLAY)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
