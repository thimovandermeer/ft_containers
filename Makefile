NAME = ft_containers
FILES = main
SRCS = $(addprefix srcs/, $(addsuffix .cpp, $(FILES)))
OBJS = $(SRCS:.cpp=.o)
INCLUDE = -Isrcs -Isrcs/list -Isrcs/queue -Isrcs/stack -Isrcs/vector -Isrcs/map

CXXFLAGS = -W -Wall -Werror -Wextra -pedantic -std=c++14 -O0

ifeq ($(shell uname), Linux)
 ECHO = -e
endif

# Colours
DARK_GREEN	= \033[0;32m
GREEN		= \033[0;92m
END			= \033[0;0m

PREFIX		= $(DARK_GREEN)$(NAME) $(END)\xc2\xbb

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(ECHO) "$(PREFIX)$(GREEN) Bundling executable... $(END)$(NAME)"
	@$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDE) -o $@

test:
	@echo $(ECHO) "$(PREFIX)$(GREEN) Running tests... $(END)$(NAME)"
	@cd tests && make run asan=1

%.a: %
	@echo $(ECHO) "$(PREFIX)$(GREEN) Compiling file $(END)$< $(GREEN)to $(END)$@"
	@make -s -C $<
	@cp $</$@ .

%.o: %.cpp
	@echo $(ECHO) "$(PREFIX)$(GREEN) Compiling file $(END)$< $(GREEN)to $(END)$@"
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo $(ECHO) "$(PREFIX)$(GREEN) Removing .o files $(END)$(OUT_DIR)"
	@rm -f $(OBJS)

fclean: clean
	@echo $(ECHO) "$(PREFIX)$(GREEN) Removing executable $(END)$(OUT_DIR)"
	@rm -rf $(NAME)
	@cd tests && make fclean

re: fclean all

run: clean all
	./$(NAME)

.PHONY: clean fclean re all test
