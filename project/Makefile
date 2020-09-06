# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sazalee <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/17 02:58:08 by sazalee           #+#    #+#              #
#    Updated: 2020/03/17 04:41:04 by sazalee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= lem-in

HEADERNAMEO		= lemin.h

HEADERNAMET		= libft.h

INCDIR 			= ./includes/

SRCDIR 			= ./srcs/

OBJDIR 			= ./objectives/

SRCNAME			= main.c antsone.c antstwo.c check.c findmore.c findshortest.c help.c link.c list.c modif.c paths.c print.c stack.c readone.c readtwo.c \
					restore.c room.c solveone.c solvetwo.c support.c free.c ft_strsplit.c get_next_line.c libftfour.c libftone.c libftthree.c libfttwo.c

HEADERO 		= $(addprefix $(INCDIR), $(HEADERNAMEO))
HEADERT			= $(addprefix $(INCDIR), $(HEADERNAMET))
SRCLEM			= $(addprefix $(SRC_PATH), $(SRCNAME))
OBJLEM			= $(addprefix $(OBJDIR), $(SRCNAME:.c=.o))

CC				= gcc
FLAGS			= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJLEM) $(HEADERO) $(HEADERT)
	@$(CC) $(addprefix -I, $(INCDIR)) $(OBJLEM) $(FLAGS) -o $(NAME)

$(OBJDIR):
	@mkdir -p objectives

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERO) $(HEADERT)
	@$(CC) -c -I $(INCDIR) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
