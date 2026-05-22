// note that most of the functions in here always that you pass in sizes of whatsoever arguments are being passed in.
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int listener_d;

void error(char msg[]){
    fprintf(stderr, "%s : %s\n", msg, strerror(errno));
    exit(1);
}

void handle_shutdown(int sig) {
    // functon to handle the shutdown of the server ^C.
    if (listener_d) close(listener_d);
    fprintf(stderr, "Server shutting down....\nbye\n");
    exit(0);
}

int mapper_custom_sig_handlers(int sig, void (*handler) (int)) {
    /*
     *custom interrupt signal handler, takes in the intended signal interrupt to be handled and then maps it to the
     * custom function(handler) the program would love to handle the specified interrupt signal.
     */
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask); // to ensure that other signals are not blocked when handling current signal.
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

int open_listener_socket() {
    int s = socket(PF_INET, SOCK_STREAM, 0); // creating a socket descriptor
    if (s == -1) error("cannot open socket.");
    return s;
}

void bind_to_socket(const int l_socket, const int port) {
    //creating the port details
    struct sockaddr_in port_details;
    port_details.sin_family = PF_INET;
    port_details.sin_port = (in_port_t)htons(port);
    port_details.sin_addr.s_addr = htonl(INADDR_ANY);

    //setting the port to be immediately reusable even if it is bound.
    const int reuse = 1;
    if (setsockopt(l_socket, SOL_SOCKET, SO_REUSEADDR, (char *) &reuse, sizeof(int)) == -1) {
        error("cannot set the reuse port option.");
    }
    // Bind
    const int c = bind(l_socket, (struct sockaddr *) &port_details, sizeof(port_details));
    if (c == -1) error("Cannot bind to the socket.");
}
int say(const int c_socket, const char *msg) {
    // BEGIN
    const int result = send(c_socket, msg, strlen(msg), 0);
    if (result == -1) {
        fprintf(stderr, "%s : %s \n", "Error talking to the client", strerror(errno));
    }
    return result;
}
int read_client_msg(int socket, char *buff, int len) {
    /* Due to possible network issues, the recv function might not be able to read all sent bytes in one go, hence the
     * need for this function to handle such - whether everything is sent at once or in batches.
     * at the end of reading every byte, this function also cleans up the '\r\n' at the end of the read message.
     */
    char *s = buff;
    int slen = len;
    int c = recv(socket, s, slen, 0);

    while ((c > 0) && (s[c-1] != '\n')) {
        s += c;
        slen -= c;
        c = recv(socket, s, slen, 0);
    }
    if (c < 0) {
        return c;
    }
    if (c == 0 && s == buff) {
        buff[0] = '\0';
        return 0;
    }

    int total_read = len - slen;

    while (total_read > 0 && (buff[total_read - 1] == '\n' || buff[total_read] == '\r')) {
        buff[total_read - 1] = '\0';
        total_read -= 1;
    }

    return  total_read;
}



int main() {
    if (mapper_custom_sig_handlers(SIGINT, handle_shutdown) == -1) {
        fprintf(stderr, "Cannot map the handler\n");
        exit(3);
    }
    // using \r\n at the end of line of messages sent to signify that each message was done transmitting as is the network standard.
    char *advice[] = {
        "Take smaller bites\r\n",
        "Go for the tight jeans. No they do NOT make you look fat.\r\n",
        "One word: inappropriate\r\n",
        "Just for today, be honest. Tell your boss what you *really* think\r\n",
        "You might want to rethink that haircut\r\n"
        };
    // the BLAB - Bind, Listen, Accept, Begin

    listener_d = open_listener_socket();

    bind_to_socket(listener_d, 30000);

    //LISTEN - waiting for attempted client connections and setting queue to size of 10
    if (listen(listener_d, 10) == -1) error("Cannot listen.");
    puts("waiting for connection.");

    // using a while loop to ensure that the server is persistent(accepting clients and closing clients in order to serve others on the queue)
    while (1){
        // ACCEPT - Creating a struct to be passed in to the accept function this struct would be populated with the client's stuff.
        struct sockaddr_storage client;
        unsigned int client_size = sizeof(client);

        const int connect_d = accept(listener_d, (struct sockaddr *) &client, &client_size); // accept wants a pointer to the sizeof client struct, unlike bind
        if (connect_d == -1) error("cannot open secondary socket."); // the connect_d descriptor is the one the server would be using

        // actual transmission
        const int byte_sent = say(connect_d, advice[rand() % 5]);
        close(connect_d);
        fprintf(stdout, "sent out %d bytes.\n", byte_sent);
    }
    return 0;
}