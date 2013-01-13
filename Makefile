CC		= g++
CFLAGS	= -c -Wall
LIBS	= -lglew -lglfw -framework Cocoa -framework OpenGL -framework IOKit
TARGET	= gltest
SOURCES	= main.cpp shader.cpp graphics.cpp renderable.cpp shaderprogram.cpp controls.cpp texture.cpp text.cpp block.cpp world.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LIBS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(TARGET)