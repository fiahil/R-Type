##
## Makefile for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client
## 
## Made by alexandre teisseire
## Login   <teisse_a@epitech.net>
## 
## Started on  Fri Jan 18 20:15:19 2013 alexandre teisseire
## Last update Sun Jan 20 10:43:08 2013 alexandre teisseire
##

NAME		= R-Type

PATH_SRC_NTK	= ./Network/
PATH_INC_NTK	= ./Network/

PATH_SRC_GM	= ./GameManager/
PATH_INC_GM	= ./GameManager/

PATH_SRC_GC	= ./GameComponent/
PATH_INC_GC	= ./GameComponent/

PATH_SRC_IN	= ./Input/
PATH_INC_IN	= ./Input/

PATH_SRC_SS	= ./SpriteSheet/
PATH_INC_SS	= ./SpriteSheet/

PATH_SRC_WIN	= ./Window/
PATH_INC_WIN	= ./Window/

PATH_SRC_STG	= ./Stage/
PATH_INC_STG	= ./Stage/

PATH_SRC_REQ	= ../Generics/ReqCl/sources/
PATH_SRC_LOG    = ../Generics/Logger/

PATH_INC_REQ    = ../Generics/ReqCl/include/
PATH_INC_LOG    = ../Generics/Logger/

PATH_INC_CMD	= ../Generics/Cmd/

PATH_SFML	= ./SFML-Unix/include/

SRC		= $(PATH_SRC_NTK)NetworkManager.cpp	\
		$(PATH_SRC_NTK)TCPService.cpp		\
		$(PATH_SRC_NTK)UDPService.cpp		\
		$(PATH_SRC_NTK)PackMan.cpp		\
		$(PATH_SRC_NTK)PackManUDP.cpp		\
		main.cpp

SRC_CL		= $(PATH_SRC_REQ)CSRequest.cpp		\
		  $(PATH_SRC_REQ)SCRequest.cpp

SRC_LOG		= $(PATH_SRC_LOG)logger.cpp

SRC_GM		= $(PATH_SRC_GM)GameManager.cpp

SRC_SS		= $(PATH_SRC_SS)sfSpriteSheet.cpp

SRC_GC		= $(PATH_SRC_GC)GameComponent.cpp	\
		  $(PATH_SRC_GC)IGameComponent.cpp

SRC_IN		= $(PATH_SRC_IN)sfJoystick.cpp		\
		  $(PATH_SRC_IN)sfKeyboard.cpp		\
		  $(PATH_SRC_IN)sfMouse.cpp

SRC_WIN		= $(PATH_SRC_WIN)sfWindow.cpp

SRC_STG		= $(PATH_SRC_STG)Stage.cpp

OBJ		= $(SRC:.cpp=.o)

OBJ_LOG		= $(SRC_LOG:.cpp=.o)

OBJ_CL		= $(SRC_CL:.cpp=.o)

OBJ_GM		= $(SRC_GM:.cpp=.o)

OBJ_GC		= $(SRC_GC:.cpp=.o)

OBJ_SS		= $(SRC_SS:.cpp=.o)

OBJ_IN		= $(SRC_IN:.cpp=.o)

OBJ_WIN		= $(SRC_WIN:.cpp=.o)

OBJ_STG		= $(SRC_STG:.cpp=.o)

INCLUDES	= -I$(PATH_INC_REQ)			\
		  -I$(PATH_INC_LOG)			\
		  -I$(PATH_INC_NTK)			\
		  -I$(PATH_INC_GM)			\
		  -I$(PATH_INC_GC)			\
		  -I$(PATH_INC_IN)			\
		  -I$(PATH_INC_SS)			\
		  -I$(PATH_INC_WIN)			\
		  -I$(PATH_INC_CMD)			\
		  -I$(PATH_INC_STG)			\
		  -I$(PATH_SFML)

CXX		= g++

CXXFLAGS	= -Wall -Wextra -O3 $(INCLUDES) $(LDFLAGS) -std=c++0x -g3

LDFLAGS		= -lboost_system -lpthread -L./SFML-Unix/lib/  -Wl,--rpath=./SFML-Unix/lib/ -lsfml-graphics -lsfml-window -lsfml-system

RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_LOG) $(OBJ_CL) $(OBJ_GM) $(OBJ_IN) $(OBJ_WIN) $(OBJ_STG) $(OBJ_SS) $(OBJ_GC)
		$(CXX) -o $(NAME) $(OBJ) $(OBJ_LOG) $(OBJ_CL) $(OBJ_GM) $(OBJ_IN) $(OBJ_WIN) $(OBJ_STG) $(OBJ_SS) $(OBJ_GC) $(LDFLAGS)

clean:
		$(RM) $(OBJ) $(OBJ_LOG) $(OBJ_CL) $(OBJ_GM) $(OBJ_IN) $(OBJ_WIN) $(OBJ_STG) $(OBJ_SS) $(OBJ_GC)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
