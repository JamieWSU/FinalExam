CC=gcc
CFLAGS:=-fPIC

SRCDIR=.
PRONAME=meow.bin
SRC:=$(wildcard $(SRCDIR)/*.c)
OBJECTS=$(SRC:.c=.o)
INCLUDES:=tree.h

# Need to build:
# 	tree.o
# 	grades.o
# 	grades
# 	libtree.so
objs: $(SRC)
	$(CC) $(CFlAGS) $(INCLUDES) -c $(SRC)
lib: $(OBJS)
	$(CC) $(CFLAGS)  tree.c -shared -o libtree.so
test:
	valgrind --leak-check=full ./$(PRONAME) grades.txt
clean:
	rm -f libtree.so
	rm -f $(PRONAME)
	rm -f $(OBJECTS)

dist: $(OBJECTS)
	-tar -zcf woof.tar $(OBJECTS) $(INCLUDEDS) $(SRC) $(PRONAME) libtree.so
all: $(OBJECTS) 
	make lib
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PRONAME)
