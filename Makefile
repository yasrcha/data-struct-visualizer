CC = C:/raylib/w64devkit/bin/gcc.exe
CFLAGS = -Wall -Iinclude
LDFLAGS = -Llib
LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
TARGET = bin/visualizer.exe

all: $(TARGET)

$(TARGET): src/*.c
	mkdir -p bin
	$(CC) src/*.c $(CFLAGS) $(LDFLAGS) $(LIBS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f bin/*.exe
