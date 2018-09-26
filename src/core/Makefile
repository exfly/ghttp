CC = gcc

CSAPP_INC = ./lib
CSAPP_SRC = ./lib
LOG_INC = ../logger
LOG_SRC = ../logger
CFLAGS = -Wall -O1 -I $(CSAPP_INC) -I . -I $(LOG_INC)
LDLIBS = -lpthread

PROGS =	core

all: $(PROGS)

$(PROGS): $(CSAPP_SRC)/csapp.o $(LOG_SRC)/log.o
$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c
$(LOG_SRC)/log.o:


.PHONY : clean
clean :
	(cd $(LOG_SRC) && make clean)
	(cd $(CSAPP_SRC) && make clean)
	-rm $(PROGS)
	-rm -f *.log
	-rm *.out
