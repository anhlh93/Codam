#Colors / base 16 / Bright
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
#Colors / Perso / Bright
ORANGE = \033[38;5;214m

#MinilibX
MLX_DIR = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_DIR)$(MLX_NAME)

#Libft
LIBFT_DIR = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)

#Variables
NAME = fractol
CC = cc
FLAGS = -Wall -Werror -Wextra -Ofast -g3
RM = rm -f
AR = ar rcs
NORM = ./includes\
	./libft/include/\
	./libft/src_lib
INCLUDE = -I ./includes/\
	-I ./libft\
	-I ./$(MLX_DIR)

#Sources
OBJ_DIR_F = obj/
SRC_DIR_F = srcs/
SRC_FUNCTIONS_F = close_program colors events extra_keyboard_actions \
	full_default_init main movements_in_window parsing \
	render utils_init fractals/burning_ship fractals/julia \
	fractals/mandelbrot \

FRACT_SRC = $(addprefix $(SRC_DIR_F), $(addsuffix .c, $(SRC_FUNCTIONS_F)))
FRACT_OBJ = $(addprefix $(OBJ_DIR_F), $(addsuffix .o, $(SRC_FUNCTIONS_F)))
IFMAKE_DIR_F = .cache_exists

#instructions
all: $(MLX) $(LIBFT) $(NAME)

$(IFMAKE_DIR_F):
	@mkdir -p $(OBJ_DIR_F)
	@mkdir -p $(OBJ_DIR_F)fractals/

$(MLX):
	@echo "$(CYAN)Compiling MinilibX...$(DEF_COLOR)"
	@make -C $(MLX_DIR)

$(LIBFT):
	@echo "$(CYAN)Getting libft ready$(DEF_COLOR)"
	@make -C $(LIBFT_DIR)

$(OBJ_DIR_F)%.o: $(SRC_DIR_F)%.c | $(IFMAKE_DIR_F)
	@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR_F)fractals/%.o: $(SRC_DIR_F)fractals/%.c | $(IFMAKE_DIR_F)
	@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(FRACT_OBJ)
	@echo "$(GREEN)Compiling fractol...$(DEF_COLOR)"
	@$(CC) $(FLAGS) -o $(NAME) $(FRACT_OBJ) $(MLX) $(LIBFT) $(INCLUDE) -lXext -lX11 -lm
	@echo "$(GREEN)Fractol ready.$(DEF_COLOR)"

bonus: all

clean:
	@echo "$(YELLOW)Removing object files$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR_F)
	@if [ -d "$(MLX_DIR)" ]; then make clean -C $(MLX_DIR); fi
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@echo "$(RED)Removing fractol...$(DEF_COLOR)"
	@rm -f $(NAME)
	@rm -f $(LIBFT_DIR)$(LIBFT_NAME)

re: fclean all
	@echo "$(BLUE)Cleaned and rebuilt everything for fractol$(DEF_COLOR)"

norm:
	@norminette $(SRC_DIR_F) $(NORM) $(LIBFT_DIR) | grep -v Norme -B1 || true
	@echo "Norminet the cat says : $(RED)M$(ORANGE)e$(YELLOW)o$(GREEN)w$(CYAN) !$(BLUE)!$(MAGENTA)!$(DEF_COLOR)"

.PHONY: all re clean fclean norm bonus