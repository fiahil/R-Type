##
## Makefile<2> for RType in /home/teisse_a//Documents/Tek3/RType/Client
## 
## Made by alexandre teisseire
## Login   <teisse_a@epitech.net>
## 
## Started on  Sun Jan 13 01:24:40 2013 alexandre teisseire
## Last update Tue Jan 15 19:24:42 2013 alexandre teisseire
##

NAME	= testClient

SRCXX	= test_client.cpp						

INCLUDE = -I../../Server/Network/include/

CC	= g++

OBJXX	= $(SRCXX:.cpp=.o)

RM	= rm -f

LIB	= -lboost_system -lpthread

CXXFLAGS = -W -Wall -Werror $(INCLUDE) $(LIB)  -std=c++0x -g3

all :		$(NAME)

$(NAME) :	$(OBJXX)
		$(CC) -o $(NAME) $(OBJXX) $(LIB)

clean :
		$(RM) $(OBJXX)

fclean :	clean
		$(RM) $(NAME)

re :		fclean all
