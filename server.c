#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <unistd.h> 

int main(){

    char server_message[256] = "you have reached the server!";
    
    
 

    /*
     * Create the server socket
    */
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    //specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002); // host to 
    server_address.sin_addr.s_addr = INADDR_ANY; // 0.0.0.0

    // TODO(3) use a specic IP address
    
    //bind the socket to our specified IP and port
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    
    listen(server_socket, 5);
    
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);
    
    //send the message
    send(client_socket, server_message, sizeof(server_message), 0);
    
    //close socket
    close(server_socket);

    // TODO(1): show message that the server is running and waiting for a client connection
    // TODO(2): fix bug in the client, release all the resources.



    
    return 0;
    
}