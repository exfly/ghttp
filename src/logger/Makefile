CC = gcc

CSAPP_INC =
CSAPP_SRC =
LDLIBS = -lpthread
CFLAGS = -Wall -O2 -I .
PROGS =	example

all: log.o

log.o:

${PROGS}: log.o

.PHONY : clean

clean :
	-rm -rf $(PROGS) *.o
	-rm -rf *.log
