# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:34:58 by aaljaber          #+#    #+#              #
#    Updated: 2023/02/27 10:35:58 by aaljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SETSPEEDSRC = ./MYTESTER/SET/speedTests.cpp  
SETSPEEDOBJ = ${SETSPEEDSRC:.cpp=.o}

MAPSPEEDSRC = ./MYTESTER/MAP/speedTests.cpp  
MAPSPEEDOBJ = ${MAPSPEEDSRC:.cpp=.o}

VECSPEEDSRC = ./MYTESTER/VECTOR/speedTests.cpp  
VECSPEEDOBJ = ${VECSPEEDSRC:.cpp=.o}

STCSPEEDSRC = ./MYTESTER/STACK/speedTests.cpp  
STCSPEEDOBJ = ${STCSPEEDSRC:.cpp=.o}

SETFUNCSRC = ./MYTESTER/SET/randomTests.cpp  
SETFUNCOBJ = ${SETFUNCSRC:.cpp=.o}

MAPFUNCSRC = ./MYTESTER/MAP/randomTests.cpp  
MAPFUNCOBJ = ${MAPFUNCSRC:.cpp=.o}

VECFUNCSRC = ./MYTESTER/VECTOR/randomTests.cpp  
VECFUNCOBJ = ${VECFUNCSRC:.cpp=.o}

STCFUNCSRC = ./MYTESTER/STACK/randomTests.cpp  
STCFUNCOBJ = ${STCFUNCSRC:.cpp=.o}

SRC = ./TESTCASES/map/copy.cpp
OBJ = ${SRC:.cpp=.o}

NAME = ft_containers

CXX = c++

CXXFLAGS = -Wall -Wextra -std=c++98 -g
	
RM = rm -rf

all : ${OBJ}
		@${CXX} ${CXXFLAGS} ${OBJ} -o ft_containers

map_test : 
		@${CXX} ${CXXFLAGS} -c ${MAPFUNCSRC} -o ${MAPFUNCOBJ}
		@${CXX} ${CXXFLAGS} ${MAPFUNCOBJ} -D NAMESPACE=ft -o ft_map
		@${CXX} ${CXXFLAGS} ${MAPFUNCOBJ} -o std_map

set_test :
		@${CXX} ${CXXFLAGS} -c ${SETFUNCSRC} -o ${SETFUNCOBJ}
		@${CXX} ${CXXFLAGS} ${SETFUNCOBJ} -D NAMESPACE=ft -o ft_set
		@${CXX} ${CXXFLAGS} ${SETFUNCOBJ} -o std_set

vector_test : 
		@${CXX} ${CXXFLAGS} -c ${VECFUNCSRC} -o ${VECFUNCOBJ}
		@${CXX} ${CXXFLAGS} ${VECFUNCOBJ} -D NAMESPACE=ft -o ft_vector
		@${CXX} ${CXXFLAGS} ${VECFUNCOBJ} -o std_vector

stack_test :
		@${CXX} ${CXXFLAGS} -c ${STCFUNCSRC} -o ${STCFUNCOBJ}
		@${CXX} ${CXXFLAGS} ${STCFUNCOBJ} -D NAMESPACE=ft -o ft_stack
		@${CXX} ${CXXFLAGS} ${STCFUNCOBJ} -o std_stack
		
map_speed : 
		@${CXX} ${CXXFLAGS} -c ${MAPSPEEDSRC} -o ${MAPSPEEDOBJ}
		@${CXX} ${CXXFLAGS} ${MAPSPEEDOBJ} -D NAMESPACE=ft -o ft_map
		@${CXX} ${CXXFLAGS} ${MAPSPEEDOBJ} -o std_map

set_speed :
		@${CXX} ${CXXFLAGS} -c ${SETSPEEDSRC} -o ${SETSPEEDOBJ}
		@${CXX} ${CXXFLAGS} ${SETSPEEDOBJ} -D NAMESPACE=ft -o ft_set
		@${CXX} ${CXXFLAGS} ${SETSPEEDOBJ} -o std_set

vector_speed : 
		@${CXX} ${CXXFLAGS} -c ${VECSPEEDSRC} -o ${VECSPEEDOBJ}
		@${CXX} ${CXXFLAGS} ${VECSPEEDOBJ} -D NAMESPACE=ft -o ft_vector
		@${CXX} ${CXXFLAGS} ${VECSPEEDOBJ} -o std_vector

stack_speed :
		@${CXX} ${CXXFLAGS} -c ${STCSPEEDSRC} -o ${STCSPEEDOBJ}
		@${CXX} ${CXXFLAGS} ${STCSPEEDOBJ} -D NAMESPACE=ft -o ft_stack
		@${CXX} ${CXXFLAGS} ${STCSPEEDOBJ} -o std_stack

clean : 
		@${RM} ${MAPSPEEDOBJ}
		@${RM} ${SETSPEEDOBJ}
		@${RM} ${STCSPEEDOBJ}
		@${RM} ${VECSPEEDOBJ}
		@${RM} ${MAPFUNCOBJ}
		@${RM} ${SETFUNCOBJ}
		@${RM} ${STCFUNCOBJ}
		@${RM} ${VECFUNCOBJ}
		@${RM} ${OBJ}
	


fclean : clean
		@${RM} ${NAME} ft_map std_map std_stack ft_stack ft_vector std_vector ft_set std_set ft_containers
 
re : fclean all