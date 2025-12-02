
SHELL := /bin/bash
CC := gcc
CFLAGS := -Wall -Wextra -O2

SRC := test.c
TARGET := test

.PHONY: all clean list

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

list:
	ls -la
	@echo "$(shell ls -la)"
	