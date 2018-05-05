.PHONY: clean clean_objs fclean re r g
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ODIR = objs/
SDIR = srcs/
LDIR = ../libft/
IDIR = includes/
NAME = ../ft_unarchive
LIB = $(LDIR)libft.a
DLIB = $(LDIR)dlibft.a
FILES = main.c
OBJS = $(FILES:.c=.o)

all: $(NAME) $(NAME)

$(NAME): $(LIB) $(addprefix $(ODIR), $(OBJS))
	@echo "\xb[34m\nCompiling $@\xb[0m"
	$(CC) $(CFLAGS) -I$(IDIR) -o $@ $^

$(LIB):
	@echo "\xb[35m\nCompiling $(notdir $@)\xb[0m"
	@$(MAKE) -C $(dir $@) $(notdir $@)
	@echo "\xb[35m\n$(notdir $@) compiled\xb[0m"

$(DLIB):
	@echo "\xb[35mCompiling libft with g flag\xb[0m"
	@$(MAKE) -C $(LDIR) g

g: $(DLIB)
	@echo "\xb[34mCompiling $(NAME) with g flag\xb[0m"
	@$(CC) $(CFLAGS) -I$(IDIR) -g -o $(NAME) $(addprefix $(SDIR), $(FILES)) $(LDIR)dlibft.a

$(addprefix $(ODIR), %.o): $(addprefix $(SDIR), %.c)
	@printf "."
	@$(CC) $(CFLAGS) -I$(IDIR) -c -o $@ $<

clean: clean_objs
	@$(MAKE) -C $(LDIR) clean

clean_objs:
	@echo "\xb[3mRemoving the object files of $(NAME)\xb[0m"
	@rm -f $(addprefix $(ODIR), $(OBJS))

fclean: clean_objs
	@$(MAKE) -C $(LDIR) fclean
	@echo "\xb[3mRemoving the $(NAME)\xb[0m"
	@rm -rf $(NAME) $(NAME).dSYM

re:
	@$(MAKE) fclean
	@$(MAKE)
