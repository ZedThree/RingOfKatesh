BIN_NAME = ring

BASEPATH = $(shell pwd)
SRCPATH = $(BASEPATH)/src
OBJPATH = $(BASEPATH)/obj
BINPATH = $(BASEPATH)/bin

CC=g++

CFLAGS = --std=c++11 -Wall -pipe

SRC_EXT = c++

FILES = dice.c++\
	exits.c++\
	dungeon.c++\
	creature.c++\
	potion.c++\
	room.c++\
	player.c++\
	engine.c++\
	ring.c++
# FILES = $(shell find $(SRCPATH)/ -name '*.$(SRC_EXT)')

FILELIST = $(addprefix $(SRCPATH)/,$(FILES))

OBJECTS = $(FILELIST:$(SRCPATH)/%.c++=$(OBJPATH)/%.o)
# OBJLIST := $(addprefix $(OBJPATH)/,$(OBJECTS))

DEPS = $(OBJECTS:.o=.d)

all: dirs $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BINPATH)/$(BIN_NAME) $(FILELIST)

.PHONY: dirs
dirs:
	@echo "Making directories"
	@mkdir -p $(OBJPATH)
	@mkdir -p $(BINPATH)

-include $(DEPS)

$(OBJPATH)/%.o: $(SRCPATH)/%.c++
	$(CC) $(CFLAGS) -MP -MMD -c $< -o $@

.PHONY: clean
clean:
	@rm -r $(OBJPATH)
