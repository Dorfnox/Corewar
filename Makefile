# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpierce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 10:27:14 by bpierce           #+#    #+#              #
#    Updated: 2018/05/29 13:35:12 by bpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COREWAR = corewar
ASSEMBLER = asm

COREWAR_DIRECTORY = virtual_machine/
ASSEMBLER_DIRECTORY = assembler/

COREWAR_HEADERS = $(COREWAR_DIRECTORY)/inc/$(COREWAR).h
ASSEMBLER_HEADERS = $(ASSEMBLER_DIRECTORY)/inc/$(asm).h

FILES = main

C_FLAGS = -Wall -Wextra -Werror

LIB_LOC = libft/
LIB_NAM = libft.a
LIB_SRC = $(addprefix $(LIB_LOC), $(LIB_NAM))

HEADER_LOCATIONS = -I libft/inc -I $(COREWAR_DIRECTORY)/inc -I $(ASSEMBLER_DIRECTORY)/inc
HEADERS = $(COREWAR_HEADERS) $(ASSEMBLER_HEADERS)

RED = [31m
GREEN = [32m
BLUE = [34m
YELLOW = [33m
MAGENTA = [35m
GREY = [37m
GREEN_LIGHT = [92m
YELLOW_LIGHT = [93m
YELLOW_BOLD = [1;33m
MAGENTA_LIGHT = [95m
BLINK = [5m
END_COLOUR = [0m

all: $(COREWAR) $(ASSEMBLER)

$(COREWAR): $(LIB_SRC)
	@echo "$(YELLOW)----------- Checking $@ -----------$(END_COLOUR)"
	@echo "Running make in $@ directory"
	@make -C $(COREWAR_DIRECTORY)
	@cp $(COREWAR_DIRECTORY)/$(COREWAR) .
	@echo "$(YELLOW)----------- $@ Check Complete -----------$(END_COLOUR)"

$(ASSEMBLER): $(LIB_SRC)
	@echo "$(YELLOW)----------- Checking $@ -----------$(END_COLOUR)"
	@echo "Running make in $@ directory"
	@make -C $(ASSEMBLER_DIRECTORY)
	@cp $(ASSEMBLER_DIRECTORY)/$(ASSEMBLER) .
	@echo "$(YELLOW)----------- $@ Check Complete -----------$(END_COLOUR)"

$(LIB_SRC): force
	@echo "$(YELLOW)----------- Checking $@ -----------$(END_COLOUR)"
	@printf "$(YELLOW_LIGHT)$@ re-compile status: $(END_COLOUR)"
	@make -C $(LIB_LOC)
	@echo "$(YELLOW)----------- $@ Check Complete -----------$(END_COLOUR)"

force:
	@true

clean:
	@make clean -C $(COREWAR_DIRECTORY)
	@make clean -C $(ASSEMBLER_DIRECTORY)
	@make clean -C $(LIB_LOC)
	@echo "$(GREEN)clean complete!$(END_COLOUR)"

fclean: clean
	@make fclean -C $(COREWAR_DIRECTORY)
	@make fclean -C $(ASSEMBLER_DIRECTORY)
	@make fclean -C $(LIB_LOC)
	@rm -rf $(ASSEMBLER)
	@rm -rf $(COREWAR)
	@echo "$(GREEN)fclean complete!$(END_COLOUR)"

re: fclean all

.PHONY: all force clean fclean re
