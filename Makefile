TARGET  =  biblioteca

COMPILER = gcc
CFLAGS = -Wall -g -Wextra

SRC = main.c functii.c 

build:
	$(COMPILER) $(CFLAGS) $(SRC) -o $(TARGET)

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET)