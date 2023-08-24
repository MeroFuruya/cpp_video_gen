OUT_DIR = bin

ifeq ($(OS),Windows_NT)
	# Windows
	SHELL = cmd
	RM = del /Q
	MKDIR = if not exist $(call FIXPATH,$(OUT_DIR)) mkdir $(call FIXPATH,$(OUT_DIR))
	RMDIR = rmdir /S /Q $(call FIXPATH,$(OUT_DIR))
	FIXPATH = $(subst /,\,$1)
	EXECUTABLE = bin\main.exe
else
	# Linux
	RM = rm -f
	MKDIR = mkdir -p $(call FIXPATH,$(OUT_DIR))
	RMDIR = rm -rf $(call FIXPATH,$(OUT_DIR))
	FIXPATH = $1
	EXECUTABLE = bin/main
	INCLUDE_DIRS = /usr/local/include /usr/include /usr/local/include/CImg /usr/include/ffmpeg
	LIB_DIRS = /usr/local/lib /usr/lib /usr/X11R6/lib /usr/lib/x86_64-linux-gnu/
	LDFLAGS = /usr/lib/x86_64-linux-gnu/libX11.so -L/usr/lib/x86_64-linux-gnu
endif

CC=g++
INCLUDE_DIRS+=./include
LIB_DIRS+=
CFLAGS=-c -Wall $(addprefix -I,$(INCLUDE_DIRS)) $(addprefix -L,$(LIB_DIRS)) -lm -lpthread
LDFLAGS+=-lX11
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(addprefix $(OUT_DIR)/,$(notdir $(SOURCES:.cpp=.o)))

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(MKDIR)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 

bin/%.o: src/%.cpp
	$(MKDIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RMDIR)