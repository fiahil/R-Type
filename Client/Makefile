##
## Makefile for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client
## 
## Made by alexandre teisseire
## Login   <teisse_a@epitech.net>
## 
## Started on  Fri Jan 18 20:15:19 2013 alexandre teisseire
## Last update Sat Jan 19 20:16:32 2013 alexandre teisseire
##

NAME		= R-Type

PATH_SRC_NTK	= ./Network/
PATH_INC_NTK	= ./Network/

PATH_SRC_GM	= ./GameManager/
PATH_INC_GM	= ./GameManager/

PATH_SRC_IN	= ./Input/
PATH_INC_IN	= ./Input/

PATH_SRC_WIN	= ./Window/
PATH_INC_WIN	= ./Window/

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

SRC_IN		= $(PATH_SRC_IN)sfJoystick.cpp		\
		  $(PATH_SRC_IN)sfKeyboard.cpp		\
		  $(PATH_SRC_IN)sfMouse.cpp

SRC_WIN		= $(PATH_SRC_WIN)sfWindow.cpp

OBJ		= $(SRC:.cpp=.o)

OBJ_LOG		= $(SRC_LOG:.cpp=.o)

OBJ_CL		= $(SRC_CL:.cpp=.o)

OBJ_GM		= $(SRC_GM:.cpp=.o)

OBJ_IN		= $(SRC_IN:.cpp=.o)

OBJ_WIN		= $(SRC_WIN:.cpp=.o)

INCLUDES	= -I$(PATH_INC_REQ)			\
		  -I$(PATH_INC_LOG)			\
		  -I$(PATH_INC_NTK)			\
		  -I$(PATH_INC_GM)			\
		  -I$(PATH_INC_IN)			\
		  -I$(PATH_INC_WIN)			\
		  -I$(PATH_INC_CMD)			\
		  -I$(PATH_SFML)

CXX		= g++

CXXFLAGS	= -Wall -Wextra -O3 $(INCLUDES) $(LDFLAGS) -std=c++0x -g3

LDFLAGS		= -lboost_system -lpthread -L./SFML-Unix/lib/  -Wl,--rpath=./SFML-Unix/lib/ -lsfml-graphics -lsfml-window -lsfml-system

RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_LOG) $(OBJ_CL) $(OBJ_GM) $(OBJ_IN) $(OBJ_WIN)
		$(CXX) -o $(NAME) $(OBJ) $(OBJ_LOG) $(OBJ_CL) $(OBJ_GM) $(OBJ_IN) $(OBJ_WIN) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
