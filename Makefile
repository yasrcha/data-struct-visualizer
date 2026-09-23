CC = gcc
CFLAGS = -Wall -Iinclude -Iinclude/gui
LDFLAGS = -Llib -lraylib -lopengl32 -lgdi32 -lwinmm -static-libgcc

TARGET = bin/DataStructVisualizer.exe

$(TARGET): src/*.c src/gui/*.c icon.o
#                                ^^^^^^^^ adicione aqui
	mkdir -p bin
	$(CC) src/*.c src/gui/*.c icon.o $(CFLAGS) $(LDFLAGS) -o $(TARGET)
#                              ^^^^^^^^ e aqui

icon.o: icon.rc icon.ico
	windres icon.rc -O coff -o icon.o

run: $(TARGET)
	./$(TARGET)   
