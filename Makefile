##
## EPITECH PROJECT, 2024
## hola
## File description:
## No file there, just an epitech header example.
## You can even have multiple lines if you want!
##

SRC     =	src/main.c	\
			src/handling_prompts.c	\
			src/prompt.c	\
			src/check_exe.c	\
			src/prompt_functionality.c	\
			src/handle_cd.c	\
			src/handle_setenv.c	\
			lib/my_put_nbr.c	\
			lib/my_putchar.c	\
			lib/my_putstr.c		\
			lib/my_revstr.c		\
			lib/my_strcat.c		\
			lib/my_strcpy.c		\
			lib/my_strlen.c		\
			lib/my_strdup.c		\
			lib/my_strcmp.c		\
			lib/my_strncmp.c	\
			lib/my_strlowcase.c \
			lib/my_str_to_word_array.c	\
			lib/utility.c 		\
			lib/my_power.c	\
			lib/my_get_int_len.c	\
			lib/my_put_nbr1.c	\
			src/my_printf/printf.c	\
			src/my_printf/s_i_per_c_f_conversions.c	\
			src/my_printf/e_conversion.c		\
			src/my_printf/display_functions.c		\
			src/my_printf/display_functions2.c		\
			src/my_printf/u_o_x_conversions.c		\
			src/my_printf/other_conversions.c	\

OBJ     = $(SRC:.c=.o)

NAME    =	mysh

all:    $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f *.o
		rm -f ./src/*.o
		rm -f /*.gcno
		rm -f *.gcno
		rm -f *.gcda
		rm -f ./lib/*.o
		rm -f ./errors/*.o
		rm -f ./src/table_handling/*.o
		rm -f src/my_printf/*.o
		rm -f $(NAME)

fclean: clean
		rm -f $(NAME)

re:     fclean all
