CC = gcc

CSAPP_INC = ./src/lib
CSAPP_SRC = ./src/lib
LOG_INC = ./src/logger
LOG_SRC = ./src/logger
CFLAGS = -Wall -O1 -I $(CSAPP_INC) -I . -I $(LOG_INC)
LDLIBS = -lpthread

PROGS =	ghttp

all: $(PROGS)
	-mkdir log

$(PROGS): $(CSAPP_SRC)/csapp.o $(LOG_SRC)/log.o ./src/core/core.c
	gcc $(CFLAGS) -I$(CSAPP_INC) -I$(LOG_INC) $?  $(LDLIBS) -o $@

$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c

$(LOG_SRC)/log.o:


.PHONY : clean
clean :
	-rm -rf *.dSYM/
	(cd $(CSAPP_SRC) && make clean)
	(cd $(LOG_SRC) && make clean)
	-rm $(PROGS)
	-rm -rf ./log/
	-rm *.out
