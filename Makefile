CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	CUB3D

LD_FLAGS		=	-L mlx
MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEADERS		=	-I includes -I libft -I mlx
SRCS_DIR	=	srcs
OBJS_DIR	=	tmps
LIB			=	-lft -L libft
LIBFT_PATH	=	libft
LIBFT		=	${LIBFT_PATH}/libft.a

SRCS		=	$(notdir $(shell find ${SRCS_DIR} -type f -name "*.c"))
OBJS 		=	$(addprefix tmps/, $(SRCS:.c=.o))
vpath		%.c $(shell find ${SRCS_DIR} -type d)

all:			init $(NAME)

init:
			$(shell mkdir -p ${OBJS_DIR})
			@make bonus --silent -C libft
			@make --silent -C libft
			@make --silent -C mlx


$(NAME) :		${OBJS}
				@${CC} ${CFLAGS} ${OBJS} ${HEADERS} ${LIB} ${LIBFT} -o ${NAME} ${LD_FLAGS} ${MLX_FLAGS}

${OBJS_DIR}/%.o:	%.c
			@echo "compiling $<\r\c"
			@${CC} ${CFLAGS} ${HEADERS} -c $< -o $@

clean:
				@make clean -C ${LIBFT_PATH}
				@make clean -C mlx
				@rm -rf ${OBJS}

fclean:			clean
				@make fclean -C ${LIBFT_PATH}
				@rm -rf $(NAME)
				@rm -rf tmps/*.o

re:				fclean all

.PHONY:			all clean fclean re
