all: main

CXX = g++
override CXXFLAGS += -g -Wall -Werror -std=c++14

SRCS = *.cpp entidades/*.cpp daos/*.cpp managers/*.cpp
HEADERS = 

#SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
#HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.hpp' -print)

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
	NIX_HARDENING_ENABLE= $(CXX) $(CXXFLAGS) -O0  $(SRCS) -o "$@"

clean:
	rm -f main main-debug