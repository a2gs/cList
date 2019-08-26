# System shell utilities
CC = gcc
RM = rm -f
CP = cp
AR = ar
RANLIB = ranlib
CPPCHECK = cppcheck

# C flags:
CFLAGS_OPTIMIZATION = -g
#CFLAGS_OPTIMIZATION = -O3
CFLAGS_VERSION = -std=c11
CFLAGS_WARNINGS = -Wall -Wextra -Wno-unused-parameter
CFLAGS_DEFINES = -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -D_POSIX_SOURCE=1 -D_DEFAULT_SOURCE=1 -D_GNU_SOURCE=1
CFLAGS = $(CFLAGS_OPTIMIZATION) $(CFLAGS_VERSION) $(CFLAGS_WARNINGS) $(CFLAGS_DEFINES)
LIB_CLIST = clist

all: clean clistlib

clistlib:
	$(CC) -c -o $(LIB_CLIST).o $(LIB_CLIST).c -I./ $(CFLAGS)
	$(AR) rc lib$(LIB_CLIST).a $(LIB_CLIST).o
	$(RANLIB) lib$(LIB_CLIST).a
	-$(RM) $(LIB_CLIST).o

sample: clistlib
	$(CC) -o sample sample.c $(CFLAGS) -L./ -l$(LIB_CLIST)

clean:
	-$(RM) *.o core sample libclist.a clist.o
