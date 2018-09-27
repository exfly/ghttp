CC = gcc

CSAPP_INC = ./src/lib
CSAPP_SRC = ./src/lib
LOG_INC = ./src/logger
LOG_SRC = ./src/logger
CFLAGS = -Wall -O1 -I $(CSAPP_INC) -I . -I $(LOG_INC)
LDLIBS = -lpthread

PROGS =	ghttp

CORE_SRC = ./src/core

all: $(PROGS)
	-mkdir log

$(PROGS): $(CSAPP_SRC)/csapp.o $(LOG_SRC)/log.o $(CORE_SRC)/core.o
	gcc $(CFLAGS) -I$(CSAPP_INC) -I$(LOG_INC) $?  $(LDLIBS) -o $@

$(CORE_SRC)/core.o: $(CORE_SRC)/core.c $(LOG_INC)/log.h $(CSAPP_INC)/csapp.h

$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h

$(LOG_SRC)/log.o: $(LOG_INC)/log.h


.PHONY : clean

clean :
	-rm -rf *.dSYM/
	(cd $(CSAPP_SRC) && make clean)
	(cd $(LOG_SRC) && make clean)
	-rm -rf $(CORE_SRC)/core.o
	-rm $(PROGS)
	-rm -rf ./log/
	-rm *.out

test:
	echo "on null test!"
