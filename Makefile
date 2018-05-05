.PHONY: clean clean_objs fclean re r g

all:
	@for i in ex*/ libft; do\
		$(MAKE) -C $$i;\
		done\

g:
	@for i in ex*/ libft; do\
		$(MAKE) -C $$i g;\
		done\

clean: clean_objs
	@for i in ex*/ libft; do\
		$(MAKE) -C $$i clean;\
		done\


clean_objs:
	@for i in ex*/ libft; do\
		$(MAKE) -C $$i clean_objs;\
		done\

fclean:
	@for i in ex*/ libft; do\
		$(MAKE) -C $$i fclean;\
		done\

re:
	@for i in ex*/ libft; do\
		$(MAKE) -C $$i clean;\
		done\
