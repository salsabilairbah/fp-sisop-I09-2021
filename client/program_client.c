#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
  
#define PORT     8080
#define MAXLINE 1024
  
// Driver code
int main() {
    int sockfd,i=0;
    char buffer[MAXLINE];
    char data[50];
    char *clear;
    
    
    while((data[i++] = getchar()) != '\n');
    struct sockaddr_in servaddr;
    clear = strtok(data,"\n");
    
  
    
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
  
    memset(&servaddr, 0, sizeof(servaddr));
      
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
      
    int n, len;
    
    sendto(sockfd, (const char *)clear, strlen(clear),
        MSG_CONFIRM, (const struct sockaddr *) &servaddr, 
            sizeof(servaddr));
    
  
    close(sockfd);
    return 0;
}