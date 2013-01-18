##
## Makefile<2> for RType in /home/teisse_a//Documents/Tek3/RType/Client
## 
## Made by alexandre teisseire
## Login   <teisse_a@epitech.net>
## 
## Started on  Sun Jan 13 01:24:40 2013 alexandre teisseire
## Last update Fri Jan 18 15:27:31 2013 alexandre teisseire
##

NAME	= testClient

PATH_SRC_REQ	= ../../Generics/ReqCl/sources/
PATH_INC_REQ	= ../../Generics/ReqCl/include/

PATH_SRC_LOG	= ../../Generics/Logger/
PATH_INC_LOG	= ../../Generics/Logger/

SRCXX	= NetworkManager.cpp			\
	TCPService.cpp				\
	UDPService.cpp				\
	client.cpp

SRCXX_CL = $(PATH_SRC_REQ)CSRequest.cpp		\
	  $(PATH_SRC_REQ)SCRequest.cpp

SRCXX_LOG = $(PATH_SRC_LOG)logger.cpp

CC	= g++

OBJXX	= $(SRCXX:.cpp=.o)
OBJXX_LOG = $(SRCXX_LOG:.cpp=.o)
OBJXX_CL= $(SRCXX_CL:.cpp=.o)

INCLUDE	= -I../../Server/Network/include/	\
	  -I$(PATH_INC_REQ)			\
	  -I$(PATH_INC_LOG)

RM	= rm -f

LIB	= -lboost_system -lpthread

CXXFLAGS = -W -Wall -Werror $(INCLUDE) $(LIB)  -std=c++0x -g3

all :		$(NAME)

$(NAME) :	$(OBJXX) $(OBJXX_CL) $(OBJXX_LOG)
		$(CC) -o $(NAME) $(OBJXX) $(OBJXX_CL) $(OBJXX_LOG) $(LIB)

clean :
		$(RM) $(OBJXX) $(OBJXX_CL) $(OBJXX_LOG)

fclean :	clean
		$(RM) $(NAME)

re :		fclean all
