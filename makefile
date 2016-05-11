CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=  -std=c++11 -g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

SRCS=$(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRCS))

all: people_simulator

people_simulator: $(OBJS)
	$(CXX) $(LDFLAGS) -o peopleSim $(OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

%.o : %.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

include .depend

