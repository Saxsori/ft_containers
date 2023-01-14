# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:34:58 by aaljaber          #+#    #+#              #
#    Updated: 2023/01/14 20:41:51 by aaljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./TESTCASES/memory.cpp

OBJ = ${SRC:.cpp=.o}

NAME = ft_containers

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g
	
RM = rm -rf

all : ${NAME}

${NAME} : ${OBJ}
		${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

clean : 
		${RM} ${OBJ}

fclean : clean
		${RM} ${NAME}
 
re : fclean all