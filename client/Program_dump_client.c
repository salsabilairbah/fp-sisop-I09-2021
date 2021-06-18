#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 1024

void createTable(char data[]){
	
}
// Driver code
int main() {
	int sockfd;
	char buffer[MAXLINE];
	struct sockaddr_in servaddr, cliaddr;
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	int len, n;

	len = sizeof(cliaddr); //len is value/resuslt
    //ini diterima(receive) dari client ke buffer
	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
				MSG_WAITALL, ( struct sockaddr *) &cliaddr,
				&len);
	buffer[n] = '\0';
    char msg1[MAXLINE],msg2[MAXLINE],temp[MAXLINE];
	// buffer dimasukkin ke temporary
    strncpy(temp,buffer,sizeof(buffer));
    //buffer diambil kata pertama sama kedua nya
    char *msg = strtok(buffer," ");
	strncpy(msg1,buffer,sizeof(buffer));
    msg = strtok(NULL," ");
    strncpy(msg2,msg,sizeof(buffer));
    //ini dicek kata pertama sama keduanya, kalo create table blablabla
    msg = strtok(NULL," ");
    if(strcmp(msg1,"CREATE")==0){
        if(strcmp(msg2,"TABLE" )==0){
			printf("Client : %s\n", temp);
            createTable(msg);
        }
    }

	return 0;
}
