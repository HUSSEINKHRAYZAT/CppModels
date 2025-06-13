# Compiler and flags
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I $(INCDIR)

# Directories
SRCDIR   = Srcs
INCDIR   = Include
OBJDIR   = Obj

# Executable name
NAME     = bureaucrat

# Source and object files
SRC      = $(SRCDIR)/main.cpp $(SRCDIR)/Bureaucrat.cpp
OBJ      = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

# Colors
GREEN    = \033[0;32m
RED      = \033[0;31m
RESET    = \033[0m

# Rules
all: $(NAME)

# Create the executable
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)✔ $(NAME) Compiled!$(RESET)"

# Compile .cpp to .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled:$(RESET) $(RED)$@ ✔$(RESET)"

# Create Obj directory if it doesn't exist
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Clean object files
clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)🗑️  Object files removed!$(RESET)"

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  Executable removed!$(RESET)"

# Recompile everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
