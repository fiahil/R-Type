##
## Makefile for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client
## 
## Made by alexandre teisseire
## Login   <teisse_a@epitech.net>
## 
## Started on  Fri Jan 18 20:15:19 2013 alexandre teisseire
## Last update Fri Jan 18 20:38:42 2013 alexandre teisseire
##

NAME		= R-Type

PATH_SRC	= ./Network/

PATH_SRC_NTK	= ./Network/

PATH_SRC_REQ	= ../../Generics/ReqCl/sources/
PATH_SRC_LOG    = ../../Generics/Logger/

PATH_INC_REQ    = ../../Generics/ReqCl/include/
PATH_INC_LOG    = ../../Generics/Logger/

SRC		= $(PATH_SRC_NTK)NetworkManager.cpp	\
		$(PATH_SRC_NTK)TCPService.cpp		\
		$(PATH_SRC_NTK)UDPService.cpp		\
		$(PATH_SRC_NTK)PackMan.cpp		\
		$(PATH_SRC)client.cpp

SRC_CL		= $(PATH_SRC_REQ)CSReqiest.cpp		\
		$(PATH_SRC_REQ)SCRequest.cpp

SRC_LOG		= $(PATH_SRC_LOG)logger.cpp

OBJ		= $(SRC:.cpp=.o)

OBJ_LOG		= $(SRC:.cpp=.o)

INCLUDES	= -I$(PATH_INC_REQ)			\
		= -I$(PATH_INC_LOG)

CXX		= g++

CXXFLAGS	= -Wall -Wextra -O3 $(INCLUDES) -std=c++0x -g3

LDFLAGS		= -lboost_system -lpthread

RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
