CC = gcc

CSAPP_BASE_PATH = ../../../core/csapp
CSAPP_INC = $(CSAPP_BASE_PATH)
CSAPP_SRC = $(CSAPP_BASE_PATH)

CFLAGS = -Wall -O2 -I $(CSAPP_INC) -I .
LDLIBS = -lpthread

PROGS =	echo.o\
	echoclient\
	echoserveri\

all: $(CSAPP_SRC)/csapp.o $(PROGS)
$(PROGS): $(CSAPP_SRC)/csapp.o
$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h

# Programs that need more than one .o file
echoserveri: echoserveri.o echo.o

clean:
	rm -f $(PROGS) *.o *~
