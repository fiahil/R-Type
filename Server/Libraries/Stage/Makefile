##
## Makefile
##
## Autor : Mister Jingles
##

NAME	=	Stage.dll

SRC	=	$(DIRSRC)GameMod.cpp		\
		$(DIRSRC)PackedPlugin.cpp	\
		$(DIRSRC)Scenario.cpp


OBJ	=	$(patsubst $(DIRSRC)%.cpp, $(DIROBJ)%.o, $(SRC))

INC	=	-I $(DIRINC) -I ../../Gameplay/include/ -I ../../../Generics/Dl/ -I ../Entities/include/

DIRBIN	=	../../

DIRSRC	=	sources/

DIRINC	=	include/

DIROBJ	=	sources/obj/

GXX	=	g++

RM	=	rm -rf

CXXFLAGS=	-Wall -Wextra -Werror -fPIC -O3 $(INC) -std=c++11

LDFLAGS	=

all:		$(NAME)

debug:		CXXFLAGS += -DDEBUG -g3
debug:		$(NAME)

release:	$(NAME)
		strip -s $(DIRBIN)$(NAME)

dir_bin:
		@mkdir -p $(DIRBIN)

dir_obj:
		@mkdir -p $(DIROBJ)

$(OBJ):		$(DIROBJ)%.o : $(DIRSRC)%.cpp
		$(GXX) -o $@ -c $< $(CXXFLAGS)

$(NAME):	dir_bin dir_obj $(OBJ)
		$(GXX) -shared -o $(DIRBIN)$(NAME) $(OBJ) $(LDFLAGS)

clean:
		@$(RM) $(DIROBJ)$(OBJ)
		@$(RM) $(DIROBJ)
		@$(RM) *~

fclean:		clean
		@$(RM) $(DIRBIN)$(NAME)

re:		fclean all

.PHONY:		all debug release clean fclean re
