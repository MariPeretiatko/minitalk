export green=`tput setaf 2`

NAME_C = client
NAME_S = server
NAME_C_B = client_bonus
NAME_S_B = server_bonus


SRC_S = server.c
OBJ_S = server.o
SRC_C = client.c
OBJ_C = client.o


SRC_S_B = server_bonus.c
OBJ_S_B = server_bonus.o
SRC_C_B = client_bonus.c
OBJ_C_B = client_bonus.o

OBJS_F			= obj/
OBJS_F_B		= obj_bonus/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

PRINTF = ft_printf/

RM = rm -rf

all: $(NAME_C) $(NAME_S)
	@echo "${green}OK main part${reset}"
$(NAME_S): $(OBJ_S)
	@$(MAKE) -C $(PRINTF)
	@ $(CC) $(FLAGS) $(PRINTF)/libftprintf.a -o $(NAME_S) $(OBJ_S)
$(NAME_C): $(OBJ_C)
	@$(MAKE) -C $(PRINTF)
	@ $(CC) $(FLAGS) $(PRINTF)/libftprintf.a -o $(NAME_C) $(OBJ_C)
# @echo "${green}OK main part${reset}"

bonus: $(NAME_C_B) $(NAME_S_B)
	@echo "${green}OK bonus part${reset}"
$(NAME_S_B): $(OBJ_S_B)
	@$(MAKE) -C $(PRINTF)
	@ $(CC) $(FLAGS) $(PRINTF)/libftprintf.a -o $(NAME_S_B) $(OBJ_S_B) 
$(NAME_C_B): $(OBJ_C_B)
	@$(MAKE) -C $(PRINTF)
	@ $(CC) $(FLAGS) $(PRINTF)/libftprintf.a -o $(NAME_C_B) $(OBJ_C_B)
# @echo "${green}OK bonus part${reset}"

clean:
	@${RM} ${OBJ_S} ${OBJ_C}
	@${RM} ${OBJ_S_B} ${OBJ_C_B}
	@$(MAKE) fclean -C $(PRINTF) 
	@echo "${green}clean${reset}"

fclean: clean
	@${RM} ${NAME_S}
	@${RM} ${NAME_C}
	@${RM} ${NAME_S_B}
	@${RM} ${NAME_C_B}
	@echo "${green}fclean${reset}"

re: fclean all

.PHONY: all clean fclean re