.RECIPEPREFIX := >

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = main.exe

SRC = src/main.c src/dynamic_array.c src/lista_simple.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
>$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
>$(CC) $(CFLAGS) -c $< -o $@

clean:
>if exist main.exe del /Q main.exe
>if exist src\*.o del /Q src\*.o
