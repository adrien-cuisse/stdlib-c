
# Compilation mode: 'dev' or 'release'
MODE = dev

# C compiler and options
CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic -nostdinc -nolibc -O3 -fno-ident -fno-asm -fno-builtin -fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables -fno-unwind-tables
# Keep debugging info in object files
ifeq ($(MODE), dev)
	CFLAGS += -g
endif
# ASM compiler and options
AC = nasm
AFLAGS = -f elf64 # <-- nasm options

# Linker
LINKER = ld

# Output binary name
BINARY = demo

# Executable source files
SRC = $(shell ls *.c)
OBJ = $(addsuffix .o, $(SRC))

#OBJ = $(addsuffix .o, $(basename $(SRC)))

# Custom library files
LIB-SRC-C = $(shell find standard -type f -name '*.c')
LIB-OBJ-C = $(addsuffix .o, $(LIB-SRC-C))  #$(LIB-SRC-C:.c=.o)
LIB-SRC-ASM = $(shell find standard -type f -name '*.s')
LIB-OBJ-ASM = $(addsuffix .o, $(LIB-SRC-ASM))  #$(LIB-SRC-ASM:.s=.o)




###############################################################################
#                             RULES SECTION START                             #
###############################################################################

# Default action if nothing is specified
default : binary

# User binary
binary : $(BINARY)

# Library
lib : $(LIB-OBJ-C) $(LIB-OBJ-ASM)

# Lauch the executable
run: $(BINARY)
	./$(BINARY)
	@echo Program exited with code $(.SHELLSTATUS)

# Delete object files
clean:
	rm `find . | grep '\.o'` 2>/dev/null; true

# Delete everything
cleanall: clean
	rm $(BINARY) 2>/dev/null; true

# Debug the executable
debug: $(BINARY)
	gdb $(BINARY)

rebuild : cleanall binary

fulltest : rebuild run

###############################################################################
#                              RULES SECTION END                              #
###############################################################################




###############################################################################
#                             OBJECT SECTION START                            #
###############################################################################

%.c.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $(addsuffix .o, $^)

# Compile library ASM files, keep files in their directories
%.s.o : %.s
	$(AC) $(AFLAGS) $^ -o $(addsuffix .o, $^)

###############################################################################
#                              OBJECT SECTION END                             #
###############################################################################




###############################################################################
#                          EXECUTABLE SECTION STAR                            #
###############################################################################

# Create user executable
$(BINARY) : $(OBJ) $(LIB-OBJ-C) $(LIB-OBJ-ASM)
	@echo Generating executable...
	$(LINKER) -o $@ $^
ifeq ($(MODE), release)
	@echo 'Reducing executable size (release mode)'
	@strip -R .comment $@
else
	@echo Executable hasn\'t been stripped \(dev mode\)
endif

###############################################################################
#                           EXECUTABLE SECTION END                            #
###############################################################################
