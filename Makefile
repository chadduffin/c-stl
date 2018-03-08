CC=gcc
CFLAGS=-c -Wall -pedantic -std=c11

SOURCES:=$(wildcard *.c)
OBJECTS:=$(patsubst %.c, %.o, $(SOURCES))

EXECUTABLE=stl

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	rm -rf *.o $(EXECUTABLE)
