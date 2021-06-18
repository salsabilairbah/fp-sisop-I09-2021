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

int main() {
	int sockfd;
	char buffer[MAXLINE];
	struct sockaddr_in servaddr, cliaddr;
	

	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
	

	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	

	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	int len, n;

	len = sizeof(cliaddr); 

	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
				MSG_WAITALL, ( struct sockaddr *) &cliaddr,
				&len);
	buffer[n] = '\0';
    char msg1[MAXLINE],msg2[MAXLINE],temp[MAXLINE];

    strncpy(temp,buffer,sizeof(buffer));
	
    char *msg = strtok(buffer," ");
	strncpy(msg1,buffer,sizeof(buffer));
    msg = strtok(NULL," ");
    strncpy(msg2,msg,sizeof(buffer));
	char msg3[50]; 
    msg = strtok(NULL," ");
	strncpy(msg3,msg,sizeof(buffer));
    if(strcmp(msg1,"CREATE")==0){
        if(strcmp(msg2,"TABLE" )==0){
			printf("Client : %s\n", temp);
            createTable(msg);
        } else if(strcmp(msg2, "DATABASE")==0){
		//ini mkdir nya ada di folder client
			mkdir(msg3, 0777);
			printf(msg3);
		}
    }

	return 0;
}
