/******************************************************* 
*client:
*	socket()--->>connect()--->send()--->>close()
*
*
*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
//next three for inet_pton()
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define MAXLINE		4096

int main(int argc, char** argv)
{
	int sockfd, n;
	char recvline[4096], sendline[4096];
	struct sockaddr_in	serv_addr;
	
	if (argc != 2) {
		printf("usage: ./client <ipaddress>\n");
		return 0;
	}
	
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("create socket error!\n");
		return 0;
	}
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(6666);
	/////ip addr conversion, point decimal -->> binary
	if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
		printf("inet_pton error for %s\n", argv[1]);
		return 0;
	}
	
	if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
		printf("connect error!\n");
		return 0;
	}
	
	printf("send message to server: \n");
	fgets(sendline, 4096, stdin);
	if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
		printf("send message error !");
		return 0;
	}

	close(sockfd);
	return 0;
}
