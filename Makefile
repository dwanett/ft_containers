NAME = containers
CC = clang++
FLAGS = -g -Wall -Wextra -Werror -MMD -std=c++98
DIR_OBJ = obj/
DIR_D_FILE = dep/

SRC =	main.cpp

OBJ = $(addprefix $(DIR_OBJ), $(SRC:.cpp=.o))
D_FILES = $(addprefix $(DIR_D_FILE), $(SRC:.cpp=.d))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@echo "\033[0;32mCompiling $(NAME)..."
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@echo "\n\033[0mDone !"

-include $(D_FILES)

$(DIR_OBJ)%.o: %.cpp
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(DIR_D_FILE)
	@printf "\033[0;33mGenerating $(NAME) objects... %-33.33s\r" $@
	@${CC} ${FLAGS} -o $@ -c -MT $@ $< ; mv $(DIR_OBJ)*.d $(DIR_D_FILE)


clean:
	@echo "\nRemoving dependency..."
	@rm -rf $(DIR_D_FILE)
	@echo "\033[0m"
	@echo "Removing binaries..."
	@rm -rf $(DIR_OBJ)
	@rm -rf *_shrubbery
	@echo "\033[0m"

fclean:
	@echo "\033[0;31m\nDeleting dependency..."
	@rm -rf $(DIR_D_FILE)
	@echo "\033[0;31m\nDeleting objects..."
	@rm -rf $(DIR_OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\nDeleting trash..."
	@rm -rf *_shrubbery
	@echo "\033[0m"

re: fclean all

run: $(NAME)
	@./$(NAME)

.PHONY: clean fclean re run
