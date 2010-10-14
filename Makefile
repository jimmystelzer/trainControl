# Directory structure
IDIR=./include
SDIR=./src
ODIR=./obj
LDIR=./lib
BDIR=./bin

# Compilers
CC=gcc

# Flags
LDLIBS= -lpthread -lrt -lcurses
CFLAGS= -I$(IDIR) -Wall -O2

# Header files
_DEPS =  
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# Object of CPP files
_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Targets

all: trainControl

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@echo "Gerando obj $@"
	@$(CC) -c -o $@ $< $(CFLAGS) 

trainControl: $(OBJ)
	@echo "Gerando $@ com $^" 
	@$(CC) -o $(BDIR)/$@ $^ $(LDLIBS) 

.PHONY: clean
clean:
	@rm -rf $(ODIR)/*.o $(SDIR)/*~ $(IDIR)/*~ $(BDIR)/*
