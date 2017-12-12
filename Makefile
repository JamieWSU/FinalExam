CC=gcc
CFLAGS:=-fPIC

SRCDIR=.
SRC:=$(wildcard $(SRCDIR)/*.c)
OBJECTS=$(SRC:.c=.o)
INCLUDES:=tree.h

# Need to build:
# 	tree.o
# 	grades.o
# 	grades
# 	libtree.so

test:

clean:

dist: $(OBJECTS)

all:
