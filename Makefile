SRC = $(wildcard main.c)
LIB = $(wildcard includes/*.c)

OBJ = $(notdir $(patsubst %.c,%.o,$(SRC) $(LIB)))

TARGET = solve

CC = gcc
CFLAGS = -g -Wall -pedantic -W

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

$(OBJ): $(SRC) $(LIB)
	$(CC) $(CFLAGS) -c $(SRC) $(LIB)

clean:
	-rm $(OBJ)

fclean: clean
	-rm $(TARGET)

re: fclean all