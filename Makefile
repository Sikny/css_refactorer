CC=g++
CFLAGS=-Wall -std=c++11
INCLUDEPATH=-I .\\include
SRC=$(wildcard *.c*) $(wildcard source/*.c*)

all: app run

app: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS) $(INCLUDEPATH) $(LIBS)

run: app
	./app
