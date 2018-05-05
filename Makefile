.PHONY: clean fclean re r
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ODIR = objs/
SDIR = srcs/
IDIR = includes/
NAME = 
FILES =
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(addprefix $(ODIR), $(OBJS))
	@echo "\x1b[34m\nCompiling $@\x1b[0m"
	@$(CC) $(CFLAGS) -I$(IDIR) -o $@ $^

$(addprefix $(ODIR), %.o): $(addprefix $(SDIR), %.c)
	@printf "."
	@$(CC) $(CFLAGS) -I$(IDIR) -c -o $@ $<

clean:
	@echo "\x1b[31mRemoving the object files of $(NAME)\x1b[0m"
	@rm -f $(addprefix $(ODIR), $(OBJS))

fclean: clean
	@echo "\x1b[31mRemoving the $(NAME)\x1b[0m"
	@rm -rf $(NAME) $(NAME).dSYM

re:
	@$(MAKE) fclean
	@$(MAKE)

r: $(NAME)
	@echo "\x1b[32m\nRunning $(NAME)\n\x1b[0m"
	@./$<
