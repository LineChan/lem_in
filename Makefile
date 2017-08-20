NAME			:= lem-in

# Directories
SRCS			:= srcs
OBJS			:= objs
INCS			:= includes

# Subdirectories
SRCS_DIR		:= $(shell find $(SRCS) -type d)
OBJS_DIR		:= $(addprefix $(OBJS)/,$(SRCS_DIR))

# Paths
LIBS_PATH		:= libs/

# Libraries
LFT				:= -Llibs -lft
LLST			:= -Llibs -llst

LIBRARIES		:= $(LLST) $(LFT)

# Files
SRCS_FILES		:= $(shell find $(SRCS_DIR) -type f -name "main.c" -o -name "ft_*.c")
OBJS_FILES		:= $(SRCS_FILES:%.c=$(OBJS)/%.o)
INCS_FILES		:= $(shell find $(INCS)/ -type f -name "*.h")

# Compiler and shell
CC				:= gcc
CFLAGS			:= -Werror -Wall -Wextra
SIZE			:= $(shell echo "$(shell tput cols) - 16" | bc)
INCLUDES		:= -I$(INCS)

# Colors
RED				= \033[31;1m
GREEN			 = \033[32;1m
YELLOW			= \033[33;1m
BLUE			= \033[34;1m
PURPLE			= \033[35;1m
CYAN			= \033[36;1m
LGREY			= \033[37;1m
END_C			= \033[m

# String
PRINT_KO        = printf "  [$(RED)✗$(END_C)]    $(RED)-->$(END_C)    %-*s\r\033[m" "$(SIZE)"
PRINT_OK        = printf "  [$(GREEN)✓$(END_C)]   $(GREEN)%s$(END_C)\n"


# Create objs directory and all subdirectories
$(shell mkdir -p $(OBJS) $(OBJS_DIR))

all :
	make -j $(NAME)

$(NAME) : $(OBJS_FILES)
	make -C libs
	$(CC) $(FLAGS) -o $@ $(INCLUDES) $(OBJS_FILES) $(LIBRARIES)
	printf "\033[K"
	$(PRINT_OK) $(NAME)

$(OBJS)/%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ && $(PRINT_KO) $< || exit

clean :
	make -C libs clean

fclean :
	make -C libs fclean

re : fclean all

.PHONY : all clean fclean setup re
.SILENT:
