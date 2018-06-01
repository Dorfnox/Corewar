# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpierce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 10:27:14 by bpierce           #+#    #+#              #
#    Updated: 2018/05/31 13:35:57 by bpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT_ = ft_

FILES = bzero memalloc memccpy memchr memcmp memcpy memdel memmove memset \
		remalloc rememalloc memdelplus \
		putchar putchars putchar_fd putendl putendl_fd putnbr putnbr_fd \
		putstr putstr_fd puterror putnull \
		strcat strccount strccountto strchr strclr strcmp strcpy strctrim \
		strdel strdeltwo strdelthree strdelfour strdup strdupuntil strdupfrom \
		strequ strfindnreplace strfsub strfremalloc strfresize striter \
		striteri strjoin strfjoin strffjoin strremove strfremove \
		strlcat strlen \
		strmap strmapi strncat strncmp strncpy strnequ strnew strnstr strrchr \
		strrev strsplit strsplits strstr strsub strtrim strofchars \
		arraynew arraynew4d arraylen arraydel arraydup arrayprint arrayappend \
		varraynew varraydel varrayrev \
		lstadd lstdel lstdelone lstiter lstmap lstnew \
		isalnum isalpha isascii isdigit islower isprint isupper iswhitespace \
		isstrdigits isstrprints \
		swap tolower toupper strtolower strtoupper itoa itoa_base atoi \
		intarrayfromstr setnull striswhitespace \
		setdoubletozero setunsignedinttozero setunsignedshorttozero \
		gnl gnlfreeall \
		abs sign powerof rgb_to_hex shade_colour percentof \
		unsignedintlen putunsignedint \
		wtoi strwtoi \
		pf_printf pf_pflite \
	   	pf_manage_printlst pf_manage_percentid pf_manage_datafmt \
		pf_set_percentid pf_set_helper \
		pf_character pf_string pf_signedint pf_unsignedint pf_percent \
		pf_widechar pf_widestr pf_free_funcs pf_wcharfuncs1 pf_wcharfuncs2 \
		sandwichjoin sandwichfjoin sandwichffjoin trim strsplice strfnew \
		debug concat_params strremovequotes strfremovequotes clearterminal \
		strreplace cursor cursormore \
		str256 \
		stack queue \
		getfilecontents printbits hex_stuff hex_stuff2

NUM_FILES = $(words $(FILES))

FUNCS = $(sort $(addprefix $(FT_), $(FILES)))

C_LOC = src/
C_NAM = $(addsuffix .c, $(FUNCS))
C_SRC = $(addprefix $(C_LOC), $(C_NAM))

O_LOC = obj/
O_NAM = $(C_NAM:.c=.o)
O_SRC = $(addprefix $(O_LOC), $(O_NAM))

H_LOC = -I inc

C_FLAGS = -Wall -Wextra -Werror

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
END_COLOUR = \033[0m

COUNTER = 0

all: $(NAME)

$(NAME): $(O_SRC)
	@echo "$(YELLOW_LIGHT)\nBuilding $@...$(END_COLOUR)"
	@ar rcs $@ $(O_SRC)
	@echo "$(GREEN) Library Complete!$(END_COLOUR)"

$(O_LOC)%.o: $(C_LOC)%.c
	@$(eval COUNTER = $(shell echo $$(( $(COUNTER) + 1 ))))
	@gcc $(C_FLAGS) $(H_LOC) -o $@ -c $<
	@printf "\033[10000D"
	@./bin/loading_bar $(COUNTER) $(NUM_FILES) 30

clean:
	@/bin/rm -rf $(O_SRC)
	@echo "$(GREEN_LIGHT)cleaned libft!$(END_COLOUR)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(GREEN_LIGHT)fcleaned libft!$(END_COLOUR)"

re: fclean all

.PHONY: all clean fclean re
