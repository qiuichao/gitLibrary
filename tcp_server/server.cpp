/*******************************************************
 *server:
 *	socket()--->>bind()--->>listen()
*	-->accept()--->>recv()--->>close()
*
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXLINE		4096

int main(int argc, char** argv)
{
	int listenfd, connfd;
	struct sockaddr_in serv_addr;
	char buff[MAXLINE];
	int n;
	
	/////socket()
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
		return 0;	
	}
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;  //ipv4
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //appoint 0.0.0.0, represent interminate addr
	serv_addr.sin_port = htons(6666);  //port 6666
	
	/////bind()
	if (bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
		printf("bind socket error: %s(error: %d)\n", strerror(errno), errno);
		return 0;
	}
	
	/////listen()
	if ( listen(listenfd, 10) == -1) {
		printf("listen socket error");
		return 0;
	}

	printf("============waiting for client's request=====================\n");
	while (1) {
		/////connect()
		if ( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1) {
			printf("accept socket error\n");
			continue;
		}
		/////recv()
		n = recv(connfd, buff, MAXLINE, 0);
		buff[n] = '\0';
		printf("recv msg client:%s\n", buff);
		close(connfd);
	}
	
	close(listenfd);
	return 0;
}
