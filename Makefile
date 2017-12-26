IDIR = include

SDIR = src
CC=g++
CFLAGS=-I$(IDIR) -g -Wall -std=c++11

ODIR=$(SDIR)/obj
LDIR =../lib

LIBS=-lm -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window 

_DEPS = HotSynapseGame.hpp GameScreen.hpp MatchScreen.hpp MatchMap.hpp MapTile.hpp EmptyTile.hpp WallTile.hpp SoldierTile.hpp OccupancyTile.hpp Soldier.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hotsynapse.o HotSynapseGame.o MatchScreen.o MatchMap.o MapTile.o EmptyTile.o WallTile.o SoldierTile.o OccupancyTile.o
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
