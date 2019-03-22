
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/result

SRC= main.c addToLibrary.c removeFromLibrary.c listing.c 

UNT_DIR = ../unity

# generic build details

CC=      cc
COPT=    -O
CFLAGS= 

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE) 

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

#test_addToLibrary.o: test_addToLibrary.c addToLibrary.h
main.o:  main.c addToLibrary.h  
addToLibrary.o:  addToLibrary.c addToLibrary.h 
removeFromLibrary.o:  removeFromLibrary.c removeFromLibrary.h
listing.o: listing.c listing.h

