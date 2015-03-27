EXEC = TPlibre
CFLAGS = -g -Wall 
CC = gcc
LIB =

INC_PATH = include/
OBJ_PATH = obj/
OBJECTS = main.o polyedre.o
OBJECTS_DIR = $(patsubst %.o, obj/%.o, $(OBJECTS))
vpath %.h include/
vpath %.c src/
vpath %.o obj/

vpath $(EXEC) bin/

$(EXEC) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_DIR) $(LIB)
	mv $@ bin/.
	
main.o : polyedre.h
polyedre.o : polyedre.h sommet.h

%.o : %.c
	$(CC) $(CFLAGS) -c $<  -I $(INC_PATH)
	mv $@ obj/.
	
archive :
	tar -czvf $(EXEC).zanzi.tar.gz ./* 
	
clean : 
	rm obj/* bin/* 
	
test :
	cd bin && ./$(EXEC) && cd ..
