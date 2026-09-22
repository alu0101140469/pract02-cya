CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2

PROGRAM = p02_strings
SOURCES = Alfabeto.cc Cadena.cc Lenguaje.cc p02_strings.cc
OBJECTS = $(SOURCES:.cc=.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(PROGRAM) $(OBJECTS)

.PHONY: all clean