.RECIPEPREFIX := >

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = main

SRC = src/main.c

all: $(TARGET)

$(TARGET): $(SRC)
>$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
>rm -f $(TARGET) $(TARGET).exe
