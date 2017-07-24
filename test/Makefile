SRC_DIRS = ../lib
INCLUDE_DIRS = ../lib

CPP_SRC =
CPP_SRC += $(SRC_DIRS)/can_mcp2515.cpp

OPTS =
OPTS += -g
OPTS += -std=c++14

LIBS =
LIBS += -lroboticscape

DEFS =
DEFS += -DDEBUG_EN

all: main test

main:
	g++ -o main $(LIBS) $(OPTS) -I $(INCLUDE_DIRS) main.cpp $(CPP_SRC)
test:
	g++ -o test $(LIBS) $(OPTS) -I $(INCLUDE_DIRS) $(DEFS) main.cpp $(CPP_SRC)
