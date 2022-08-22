NAME		:=	server

SRCS 		:=	main.cpp Socket.cpp EventHandler.cpp
OBJS		:=	$(SRCS:.cpp=.o)

INCLUDE_DIR	:=	./

CXX			:=	clang++
CXXFLAGS	:=	-Wall -Wextra -Werror -g #-fsanitize=address -fsanitize=undefined
LDFLAGS		:=	-Wall -Wextra -Werror -g #-fsanitize=address -fsanitize=undefined

.PHONY:	all
all		:	$(NAME)

client:
	$(CXX) $(CXXFLAGS) client.cpp -o $@

$(NAME)	:	$(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -I $(INCLUDE_DIR) -o $@

%.o		:	%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -I $(INCLUDE_DIR) -o $@

.PHONY:	clean
clean	:
	rm -f $(OBJS)

.PHONY:	fclean
fclean	:	clean
	rm -f $(NAME)

.PHONY:	re
re		:
	make fclean
	make all
