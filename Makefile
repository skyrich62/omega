CXX = /usr/local/gcc-9.2.0/bin/g++
CXXFLAGS = -std=c++2a -g
LXXFLAGS = 
LXX = $(CXX)

TARGET = main

OBJS = \
	player.o \
        object.o

all: $(TARGET)

main: $(OBJS) main.o
	$(LXX) $(LXXFLAGS) $(OBJS) main.o -o main

clean:
	rm -rf $(OBJS) $(TARGET)
