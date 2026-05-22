CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lstackandqueue
BIN = main
OBJ  = main.o graph_adj_list.o

.PHONY: all clean vis

all: $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
vis: $(BIN)
	./$(BIN) | dot -Tpdf > vis.pdf
clean:
	$(RM) -r $(BIN) $(OBJ) vis.pdf