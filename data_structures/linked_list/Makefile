CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.o stack_linked_list.o queue_linked_list.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o stack_linked_list.o queue_linked_list.o

main.o: main.c stack_linked_list.h queue_linked_list.h
	$(CC) $(CFLAGS) -c main.c

stack_linked_list.o: stack_linked_list.c stack_linked_list.h
	$(CC) $(CFLAGS) -c stack_linked_list.c

queue_linked_list.o: queue_linked_list.c queue_linked_list.h
	$(CC) $(CFLAGS) -c queue_linked_list.c

clean:
	rm -f *.o $(TARGET)

