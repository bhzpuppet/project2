
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/out

SRC= main.c game.c media.c record.c

# generic build details

CC =     gcc
CFLAGS = -Wall -O
LIBS =   -lSDL2main -lSDL2

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o: main.c game.h media.h record.h
game.o: game.c game.h
media.o: media.c media.h
record.o: record.c record.h game.h
