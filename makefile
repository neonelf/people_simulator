CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS= -std=c++11 
LDFLAGS= -L/usr/local/lib/ -lhttp_parser
LDLIBS= 

SRCS:=$(filter-out main.cpp, $(wildcard *.cpp))
SRCS:=$(filter-out maptest.cpp, $(SRCS))
OBJS:=$(subst .cpp,.o,$(SRCS))

all: map_test

map_test: $(OBJS) maptest.o
	$(CXX) $(LDFLAGS) -o maptest $(OBJS) maptest.o $(LDLIBS)

people_simulator: $(OBJS) main.o
	$(CXX) $(LDFLAGS) -o peopleSim $(OBJS) main.o $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS) main.o maptest.o

%.o : %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

include .depend

