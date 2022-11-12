OBJECTS=
CFLAGS= `pkg-config --cflags gsl` -lm -g -Wall -O3 -std=gnu11
LDLIBS= `pkg-config --libs gsl`
CC=gcc

$(p): $(OBJECTS)
