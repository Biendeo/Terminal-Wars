CXX = g++
DEBUG = -g
CXXFLAGS = -Wall -std=c++11 $(DEBUG)
LFLAGS = -Wall -std=c++11 $(DEBUG)
BINS = TerminalWars Test
OBJS = Data.o Game.o Map.o MapTile.o UI.o Unit.o UnitData.o Weapon.o
LIBS = 

all : $(BINS)

TerminalWars : Main.o $(OBJS)
	$(CXX) $(LFLAGS) $^ $(LIBS) -o $@
Test : Test.o $(OBJS)
	$(CXX) $(LFLAGS) $^ $(LIBS) -o $@

Main.o : Main.cpp
Test.o :
	$(CXX) $(CXXFLAGS) -c -o Test.o ../TestTW/Test.cpp

Data.o : Data.cpp
Game.o : Game.cpp
Map.o : Map.cpp
MapTile.o : MapTile.cpp
UI.o : UI.cpp
Unit.o : Unit.cpp
UnitData.o : UnitData.cpp
Weapon.o : Weapon.cpp

clean :
	rm -f $(BINS) *.o *.exe