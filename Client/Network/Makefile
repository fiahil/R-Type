##
## Makefile<2> for RType in /home/teisse_a//Documents/Tek3/RType/Client
## 
## Made by alexandre teisseire
## Login   <teisse_a@epitech.net>
## 
## Started on  Sun Jan 13 01:24:40 2013 alexandre teisseire
## Last update Wed Jan 16 18:14:18 2013 alexandre teisseire
##

NAME	= testClient

PATH_SRC_REQ	= ../../Generics/ReqCl/
PATH_INC_REQ	= ../../Generics/ReqCl/

SRCXX	= NetworkManager.cpp	\
	TCPService.cpp		\
	UDPService.cpp		\
	client.cpp

SRCXX_CL = $(PATH_SRC_REQ)CSRequest.cpp		\
	  $(PATH_SRC_REQ)SCRequest.cpp

CC	= g++

OBJXX	= $(SRCXX:.cpp=.o)
OBJXX_CL= $(SRCXX_CL:.cpp=.o)

INCLUDE	= -I../../Server/Network/include/	\
	  -I$(PATH_INC_REQ)

RM	= rm -f

LIB	= -lboost_system -lpthread

CXXFLAGS = -W -Wall -Werror $(INCLUDE) $(LIB)  -std=c++0x -g3

all :		$(NAME)

$(NAME) :	$(OBJXX) $(OBJXX_CL)
		$(CC) -o $(NAME) $(OBJXX) $(OBJXX_CL) $(LIB)

clean :
		$(RM) $(OBJXX)

fclean :	clean
		$(RM) $(NAME)

re :		fclean all
