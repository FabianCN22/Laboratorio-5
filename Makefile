.RECIPEPREFIX := >

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = main

SRC = src/main.c src/dynamic_array.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
>$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
>$(CC) $(CFLAGS) -c $< -o $@

clean:
>rm -f $(TARGET) $(TARGET).exe src/*.o
