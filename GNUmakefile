ALL: Simple_SNAKE

SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)

OBJECTS := $(SOURCES:.cpp=.o)

%.o : %.cpp ${HEADERS}
	g++ -c $<

Simple_SNAKE: ${OBJECTS}
	g++ -o $@ ${OBJECTS}
