##
## Makefile for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client
## 
## Made by alexandre teisseire
## Login   <teisse_a@epitech.net>
## 
## Started on  Fri Jan 18 20:15:19 2013 alexandre teisseire
## Last update Sat Jan 19 17:27:03 2013 alexandre teisseire
##

NAME		= R-Type

PATH_SRC_NTK	= ./Network/
PATH_INC_NTK	= ./Network/

PATH_SRC_REQ	= ../Generics/ReqCl/sources/
PATH_SRC_LOG    = ../Generics/Logger/

PATH_INC_REQ    = ../Generics/ReqCl/include/
PATH_INC_LOG    = ../Generics/Logger/

PATH_INC_CMD	= ../Generics/Cmd/


SRC		= $(PATH_SRC_NTK)NetworkManager.cpp	\
		$(PATH_SRC_NTK)TCPService.cpp		\
		$(PATH_SRC_NTK)UDPService.cpp		\
		$(PATH_SRC_NTK)PackMan.cpp		\
		$(PATH_SRC_NTK)PackManUDP.cpp		\
		main.cpp

SRC_CL		= $(PATH_SRC_REQ)CSRequest.cpp		\
		  $(PATH_SRC_REQ)SCRequest.cpp

SRC_LOG		= $(PATH_SRC_LOG)logger.cpp

OBJ		= $(SRC:.cpp=.o)

OBJ_LOG		= $(SRC_LOG:.cpp=.o)

OBJ_CL		= $(SRC_CL:.cpp=.o)

INCLUDES	= -I$(PATH_INC_REQ)			\
		  -I$(PATH_INC_LOG)			\
		  -I$(PATH_INC_NTK)			\
		  -I$(PATH_INC_CMD)

CXX		= g++

CXXFLAGS	= -Wall -Wextra -O3 $(INCLUDES) -std=c++0x -g3

LDFLAGS		= -lboost_system -lpthread

RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_LOG) $(OBJ_CL)
		$(CXX) -o $(NAME) $(OBJ) $(OBJ_LOG) $(OBJ_CL) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
