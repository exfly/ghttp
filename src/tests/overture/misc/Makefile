CC = gcc

CSAPP_BASE_PATH = ../../../core/csapp
CSAPP_INC = $(CSAPP_BASE_PATH)
CSAPP_SRC = $(CSAPP_BASE_PATH)
CFLAGS = -Wall -O1 -I $(CSAPP_INC) -I .
LDLIBS = -lpthread

PROGS = dd2ahex	hex2dd hostinfo

all: $(PROGS)

$(PROGS): $(CSAPP_SRC)/csapp.o
$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h


.PHONY : clean

run:
	./$(PROGS)

clean :
	-rm $(PROGS)
