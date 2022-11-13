objects=
CFLAGS= `pkg-config --cflags gsl glib-2.0` -lm -g -Wall -O3 -std=gnu11
LDLIBS= `pkg-config --libs gsl glib-2.0`
CC=gcc

$(p): $(objects)
