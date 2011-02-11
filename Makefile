#----- START OF INPUT BLOCK -----#
TARGET=oostubs

# one of linux, linux64, linux64cross, sunpool
PLATFORM=linux64

CFLAGS=-Wall -O0 -g
CXXFLAGS=
LDFLAGS=-O0
ASMFLAGS=-g

# task 6 requires task5 class
OBJECT_IGNORE= task1.o task2.o task3.o task4.o

INCPATHS=
LDPATHS=
LIBS=

GDBFLAGS=
EMUFLAGS=
DEBUGFLAGS=

#----- END OF INPUT BLOCK -----#

include misc/${PLATFORM}/config.mk
include misc/rules.mk
-include misc/${PLATFORM}/rules.mk
