CPPFLAGS += -isystem -std=c++11
CXX = g++
CXXFLAGS += -w

OBJ = main.o Game.o Player.o Scoreboard.o Score_Summary.o
SRC = main.cpp Game.cpp Player.cpp Scoreboard.cpp Score_Summary.cpp
PROG = SportStats

all: ${PROG}

${PROG}: ${OBJ}
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${OBJ} -o ${PROG}

clean:
	-rm -rf *.o ${PROG} ${PROG}.dSYM

# builds a .o for each corresponding .cpp file
main.o: Game.o Player.o Scoreboard.o Score_Summary.o
	@${CXX} ${CPPFLAGS} ${CXXFLAGS} -c main.cpp

Game.o: Player.o
	@${CXX} ${CPPFLAGS} ${CXXFLAGS} -c Game.cpp

Player.o: 
	@${CXX} ${CPPFLAGS} ${CXXFLAGS} -c Player.cpp

Scoreboard.o:
	@${CXX} ${CPPFLAGS} ${CXXFLAGS} -c Scoreboard.cpp

Score_Summary.o:
	@${CXX} ${CPPFLAGS} ${CXXFLAGS} -c Score_Summary.cpp


