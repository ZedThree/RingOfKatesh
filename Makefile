EXE = ring

BASEPATH = $(shell pwd)
SRCPATH = $(BASEPATH)/src

CC=g++

CFLAGS = --std=c++11 -Wall

FILES = dice.c++ creature.c++ potion.c++ engine.c++ ring.c++
FILELIST = $(addprefix $(SRCPATH)/,$(FILES))

all:
	$(CC) $(CFLAGS) -o $(EXE) $(FILELIST)
