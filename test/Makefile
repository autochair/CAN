SRC_DIRS = ../lib
INCLUDE_DIRS = ../lib

CPP_SRC =
CPP_SRC += $(SRC_DIRS)/can_mcp2515.cpp

OPTS =
OPTS += -std=c++14

LIBS =
LIBS += -lroboticscape

all:
	g++ -o test $(LIBS) $(OPTS) -I $(INCLUDE_DIRS) main.cpp $(CPP_SRC)
