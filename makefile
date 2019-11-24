
CC_FLAGS = -ansi -Wall -Wextra -pedantic

CC = gcc

ARQUIVOS = spc.c lib_lista.c \
			 	 lib_controle_spc.c \
			 	 lib_desenha_spc.c \
			 	 lib_move_spc.c \
			 	 lib_remove_spc.c \
			 	 lib_colisao_spc.c

LINK = -lm -lncurses

space: spc.c lib_lista.c lib_lista.h  \
			 lib_controle_spc.c lib_controle_spc.h  \
			 lib_desenha_spc.c lib_desenha_spc.h \
			 lib_move_spc.c lib_move_spc.h \
			 lib_remove_spc.c lib_remove_spc.h \
			 lib_colisao_spc.c lib_colisao_spc.h
	clear
	$(CC) $(CC_FLAGS) -o space $(ARQUIVOS) $(LINK)
	
