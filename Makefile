# __    __     ______     __  __     ______     ______   __     __         ______    
#/\ "-./  \   /\  __ \   /\ \/ /    /\  ___\   /\  ___\ /\ \   /\ \       /\  ___\   
#\ \ \-./\ \  \ \  __ \  \ \  _"-.  \ \  __\   \ \  __\ \ \ \  \ \ \____  \ \  __\   
# \ \_\ \ \_\  \ \_\ \_\  \ \_\ \_\  \ \_____\  \ \_\    \ \_\  \ \_____\  \ \_____\ 
#  \/_/  \/_/   \/_/\/_/   \/_/\/_/   \/_____/   \/_/     \/_/   \/_____/   \/_____/ 
                                                                                    

SRCS = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \

#  _______       ______       ___   __       __  __       ______      
#/_______/\     /_____/\     /__/\ /__/\    /_/\/_/\     /_____/\     
#\::: _  \ \    \:::_ \ \    \::\_\\  \ \   \:\ \:\ \    \::::_\/_    
# \::(_)  \/_    \:\ \ \ \    \:. `-\  \ \   \:\ \:\ \    \:\/___/\   
#  \::  _  \ \    \:\ \ \ \    \:. _    \ \   \:\ \:\ \    \_::._\:\  
#   \::(_)  \ \    \:\_\ \ \    \. \`-\  \ \   \:\_\:\ \     /____\:\ 
#    \_______\/     \_____\/     \__\/ \__\/    \_____\/     \_____\/ 

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c



OBJS = $(SRCS:.c=.o)

OBJSB = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -I./
RM = rm -f
AR = ar rcs
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	${AR} $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS) ${OBJSB}

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

bonus : ${OBJSB}
	${AR} ${NAME} ${OBJSB}

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJSB)

.PHONY: all clean fclean re bonus
