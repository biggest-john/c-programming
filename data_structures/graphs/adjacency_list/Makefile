CC = gcc
CFLAGS = -Wall -g -I..
BIN = main

STACK_AND_QUEUE_OBJ = ../queue_linked_list.o ../stack_linked_list.o
OBJ  = main.o graph_adj_list.o

.PHONY: all clean vis

all: $(BIN)

# 1. Rule for local object files (.o) in the current directory
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 2. creating object files for the queue and stack
../%.o: ../%.c
	$(CC) $(CFLAGS) -c $< -o $@

# 3. Main binary linkage ($^ includes all local and parent objects)
$(BIN): $(OBJ) $(STACK_AND_QUEUE_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

vis: $(BIN)
	./$(BIN) | dot -Tpdf > vis.pdf

clean:
	rm -f $(BIN) $(OBJ) $(STACK_AND_QUEUE_OBJ) vis.pdf