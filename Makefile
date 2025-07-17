TARGET  =  biblioteca

COMPILER = gcc
CFLAGS = -Wall -g -Wextra `pkg-config --cflags gtk+-3.0`
LDFLGS = `pkg-config --libs gtk+-3.0`

SRC = main.c functii.c 

build:
	$(COMPILER) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLGS)

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET)