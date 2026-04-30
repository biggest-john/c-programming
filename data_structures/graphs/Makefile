CC = gcc
CFLAGS = -Wall -g
BIN = main
OBJ = main.o graph_adj_mat.o

.PHONY: all clean vis

all: $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
vis: $(BIN)
	./$(BIN) | dot -Tpdf > vis.pdf
clean:
	$(RM) -r $(BIN) $(OBJ) vis.pdf

