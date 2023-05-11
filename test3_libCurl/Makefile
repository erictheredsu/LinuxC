# my frist Makefile
CC=gcc
CFLAGS=-m64 -I. -I/home/builder/p1/BUSMB_B1/SBO/dev/Source/ThirdParty/LINUX/curl/include
LDFLAGS=-L/home/builder/p1/BUSMB_B1/SBO/dev/Source/ThirdParty/LINUX/curl/lib-x64
LDLIBS=-lcurl

LibCurl=/home/builder/p1/BUSMB_B1/SBO/dev/Source/ThirdParty/LINUX/curl/lib-x64/libcurl.so

all: main

main: main.c
	$(CC) -o main.out main.c $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	cp $(LibCurl) .

clean: 
	rm -f main.out libcurl.so