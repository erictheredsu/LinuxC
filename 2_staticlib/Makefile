# static lib 
CC:=g++
CFLAGS:=-I. -I./lib
AR:=ar crv
LDFLAGS:=-L./
LDLIBS:=-lstaticmath


all: app

app: test.o libstaticmath.a
	$(CC) -o app test.o $(CFLAGS) $(LDFLAGS) $(LDLIBS)

test.o: test.cpp
	$(CC) -c test.cpp $(CFLAGS)

libstaticmath.a: lib/StaticMath.cpp lib/StaticMath.h
	$(CC) -c lib/StaticMath.cpp
	$(AR) libstaticmath.a StaticMath.o

clean: 
	rm -f app *.o *.a