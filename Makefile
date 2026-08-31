CC = gcc
CFLAGS = -Wall -Iinclude -Iinclude/gui
LDFLAGS = -Llib -lraylib -lopengl32 -lgdi32 -lwinmm

bin/visualizer.exe: src/*.c src/gui/*.c
	mkdir -p bin
	$(CC) src/*.c src/gui/*.c $(CFLAGS) $(LDFLAGS) -o bin/visualizer.exe

run: bin/visualizer.exe
	./bin/visualizer.exe
