CC = gcc
FLAGS = -L/usr/local/lib -lwiringPi
 
all: build

build: clean lcdstats lcdprint lcdlogo lcdlight

lcdstats: obj/pcd8544_rpi.o obj/PCD8544.o 
	$(CC) -o bin/lcdstats obj/pcd8544_rpi.o obj/PCD8544.o $(FLAGS)

obj/pcd8544_rpi.o: src/pcd8544_rpi.c src/PCD8544.h
	$(CC) -c src/pcd8544_rpi.c -o obj/pcd8544_rpi.o

lcdlogo: obj/lcdlogo.o obj/PCD8544.o 
	$(CC) -o bin/lcdlogo obj/lcdlogo.o obj/PCD8544.o $(FLAGS) 

obj/lcdlogo.o: src/lcdlogo.c src/PCD8544.h
	$(CC) -c src/lcdlogo.c -o obj/lcdlogo.o

lcdprint: obj/lcdprint.o obj/PCD8544.o 
	$(CC) -o bin/lcdprint obj/lcdprint.o obj/PCD8544.o $(FLAGS) 

obj/lcdprint.o: src/lcdprint.c src/PCD8544.h
	$(CC) -c src/lcdprint.c -o obj/lcdprint.o

obj/PCD8544.o: src/PCD8544.c src/PCD8544.h
	$(CC) -c src/PCD8544.c -o obj/PCD8544.o 

lcdlight: src/lcdlight.c
	$(CC) -o bin/lcdlight src/lcdlight.c $(FLAGS)

clean:
	rm -f obj/*.o bin/*
