### Simple Makefile for the project
# dictionary_parser.c is exempted from this build because it only works to extract my clean lexicon

CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -g -I.

SRCS := error_handler.c lexical_analyzer.c main.c sytax_validator.c
OBJS := $(SRCS:.c=.o)
TARGET := main

.PHONY: all clean run rebuild

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all

run: all
	./$(TARGET)
