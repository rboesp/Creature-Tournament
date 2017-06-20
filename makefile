#got help from class video http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall 
#CXXFLAGS += -Werror 
CXXFLAGS += -Wno-unused 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Queue.o QueueNode.o main.o Creature.o Barbarian.o HarryPotter.o Vampire.o BlueMen.o Medusa.o creatureMenu.o tournament.o Validation.o

SRCS = Queue.cpp QueueNode.cpp main.cpp Creature.cpp Barbarian.cpp HarryPotter.cpp Vampire.cpp BlueMen.cpp Medusa.cpp creatureMenu.cpp tournament.cpp Validation.cpp

HEADERS = Queue.hpp QueueNode.hpp Creature.hpp Barbarian.hpp creatureMenu.hpp HarryPotter.hpp Vampire.hpp BlueMen.hpp Medusa.hpp tournament.hpp Validation.hpp 

tournament: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o tournament

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o tournament
