EXEC = TPlibre
CFLAGS = -g -Wall 
CC = gcc
LIB =

INC_PATH = include/
OBJ_PATH = obj/
OBJECTS = main.o polyedre.o fichier.o liste.o sommet.o
OBJECTS_DIR = $(patsubst %.o, obj/%.o, $(OBJECTS))
vpath %.h include/
vpath %.c src/
vpath %.o obj/

vpath $(EXEC) bin/


$(EXEC) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_DIR) $(LIB)
	mv $@ bin/.
	
main.o : polyedre.h fichier.h
polyedre.o : polyedre.h sommet.h
liste.o : polyedre.h sommet.h liste.h
fichier.o : fichier.h polyedre.h sommet.h
sommet.o : sommet.h

%.o : %.c
	$(CC) $(CFLAGS) -c $<  -I $(INC_PATH)
	mv $@ obj/.
	
archive : clean
	tar -czvf $(EXEC).zanzi.tar.gz ./* 
	
clean : 
	rm obj/* bin/* 
	
test : main.o
	 bin/$(EXEC) off/cube.off
