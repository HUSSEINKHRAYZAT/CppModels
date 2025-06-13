# Compiler and flags
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I $(INC_DIR)

# Directories
SRC_DIR  = Srcs
OBJ_DIR  = Obj
INC_DIR  = Include

# Executable name
NAME     = form

# Source and object files
SRCS     = $(SRC_DIR)/main.cpp \
           $(SRC_DIR)/Bureaucrat.cpp \
           $(SRC_DIR)/Form.cpp

OBJS     = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Colors
GREEN    = \033[0;32m
RED      = \033[0;31m
RESET    = \033[0m

# Rules
all: $(NAME)

# Create the executable
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)✔ $(NAME) Compiled!$(RESET)"

# Compile .cpp to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled:$(RESET) $(RED)$@ ✔$(RESET)"

# Create Obj directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)🗑️  Object files removed!$(RESET)"

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  Executable removed!$(RESET)"

# Recompile everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
