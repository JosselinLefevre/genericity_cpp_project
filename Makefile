CXX = g++
CXXFLAGS = -Wall -pedantic -Wextra -Werror -ansi -std=gnu++14 # -ggdb
LDFLAGS =
INCLUDES =
EXEC_NAME = projet
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cc=.o)

all : $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ)
	$(CXX) -o $(EXEC_NAME) $^ $(LDFLAGS)

%.o : %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<


.PHONY: clean

clean :
	rm -f $(EXEC_NAME) *.o

run : $(EXEC_NAME)
	./$(EXEC_NAME)
