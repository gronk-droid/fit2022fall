/* Socket tutorial

url: http://www.linuxhowtos.org/C_C++/socket.htm

*/
/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{

     int sockfd, newsockfd;  // File descriptors that store the values returned 
						     // by the socket system call and the accept system call. 
								 
	 int portno;             // Stores the port number on which the server 
							 // accepts connections.
	 
     socklen_t clilen;       // Stores the size of the address of the client. 
							 // This is needed for the accept system call.
							 							 
     int n;					 // return value for the read() and write() calls; 
							 // i.e. it contains the number of characters read or written.
	 
     char buffer[256];       // The server reads characters from the socket connection 
							 // into this buffer.
							 
     struct sockaddr_in serv_addr,   // This variable will contain the address of the server.
						cli_addr;    // This one will contain the address of the client 
						             // which connects to the server.
	 	 		
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
	 
	 
	 
	 
	 
	 // Creates a new socket. The first argument of the function is the address 
	 // domain of the socket (e.g., AF_UNIX or AF_INET). The second argument is 
	 // the type of socket (e.g., SOCK_STREAM or SOCK_DGRAM). The third argument 
	 // is the protocol, TCP for stream sockets and UDP for datagram sockets. 
	 // Set to zero and OS will select the appropriate protocol. 
	 // The socket system call returns an entry into the file descriptor table or 
	 // -1 if fails.  
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");



	 // Initializes serv_addr to zeros.
     bzero((char *) &serv_addr, sizeof(serv_addr));
	 
	 
	 
	 // Store the port number into portno
     portno = atoi(argv[1]);
	 
	 
	 
	 // Code for the address family. Always set it to AF_INET.
     serv_addr.sin_family = AF_INET;                



     // This field contains the IP address of the host. 
	 // For the server this will be the host machine on which the 
	 // server is running. The symbolic constant INADDR_ANY gets this address.														
     serv_addr.sin_addr.s_addr = INADDR_ANY;
	 
	 
	 
	 
	 // Port number. Instead of simply copying the port number to 
	 // this field, it is necessary to convert this to network byte 
	 // order using the function htons() which converts a port number 
	 // in host byte order to a port number in network byte order.
     serv_addr.sin_port = htons(portno);
	 
	 
	 
	 
	 
	 // Binds a socket to an address, in this case the address of 
	 // the current host and port number on which the server will run. 
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
 
 
 
 
 
	// Allows the process to listen on the socket for connections. 
	// The second argument of the function is the number of connections 
	// that can be waiting while the process is handling a 
	// particular connection (i.e., backlog queue). Set it to 5 which is 
	// the maximum size permitted in most systems.
	listen(sockfd,5);
	
	
	
	
	// The accept() system call causes the process to block until a client 
	// connects to the server. Thus, it wakes up the process when a connection 
	// from a client has been successfully established. It returns a new file 
	// descriptor, and all communication on this connection should be done 
	// using the new file descriptor. The second argument is a reference 
	// pointer to the address of the client on the other end of the connection, 
	// and the third argument is the size of this structure. 
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
		  
		  
		  
	 // We reach this point after a client has successfully connected to our server. 
	 // The following code initializes the buffer, and then reads from the socket. 
	 // Note that the read call uses the new file descriptor, the one returned by 
	 // accept(), not the original file descriptor returned by socket(). Note also 
	 // that the read() will block until there is something for it to read in the 
	 // socket, i.e. after the client has executed a write().		
     bzero(buffer,256);
     n = read(newsockfd,buffer,255);
     if (n < 0) error("ERROR reading from socket");
     printf("Here is the message: %s\n",buffer);
	 
	 
	 
	 
	 
	 
	 // Once a connection has been established, both ends can both read and write 
	 // to the connection. Naturally, everything written by the client will be read 
	 // by the server, and everything written by the server will be read by the client. 
	 // This code simply writes a short message to the client. The last argument of 
	 // write is the size of the message. 
     n = write(newsockfd,"I got your message",18);
     if (n < 0) error("ERROR writing to socket");
	 
	 
	 // close connections
     close(newsockfd);
     close(sockfd);
	 
	
     return 0; 
}
