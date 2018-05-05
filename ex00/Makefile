.PHONY: clean clean_objs fclean re r g

all:
	$(MAKE) -C ft_archive;
	$(MAKE) -C ft_unarchive;

g:
	$(MAKE) -C ft_archive g;
	$(MAKE) -C ft_unarchive g;

clean: clean_objs
	$(MAKE) -C ft_archive clean;
	$(MAKE) -C ft_unarchive clean;

clean_objs:
	$(MAKE) -C ft_archive clean_objs;
	$(MAKE) -C ft_unarchive clean_objs;

fclean:
	$(MAKE) -C ft_archive fclean;
	$(MAKE) -C ft_unarchive fclean;

re:
	$(MAKE) -C ft_archive re;
	$(MAKE) -C ft_unarchive re;
	
.PHONY: clean clean_objs fclean re r g
