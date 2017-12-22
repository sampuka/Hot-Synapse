IDIR = include

SDIR = src
CC=g++
CFLAGS=-I$(IDIR) -g -Wall -std=c++11

ODIR=$(SDIR)/obj
LDIR =../lib

LIBS=-lm

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hotsynapse.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

hotsynapse: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(SDIR)/*~ ircbutt $(IDIR)/*~
	rmdir $(ODIR)

$(shell mkdir -p $(ODIR))
