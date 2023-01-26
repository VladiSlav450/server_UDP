#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "erproc.h"

int main()
{
	int clientsd = Socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); 	
	struct sockaddr_in  adr, server;
	int port = 6666;
	socklen_t  server_adress_size;
	adr.sin_family = AF_INET;
	adr.sin_port = htons(port);
	adr.sin_addr.s_addr = htonl(INADDR_ANY);
	Bind(clientsd, (struct sockaddr *) &adr, sizeof adr);
	
	char buf[32];

	while(1){
		scanf("%s", buf);
		Sendto(clientsd, buf, (strlen(buf) + 1), 0, (struct sockaddr *) &server, sizeof server);	

		server_adress_size = sizeof(server);
		Recvfrom(clientsd, buf, sizeof buf, 0, (struct sockaddr *) &server,  &server_adress_size);
		printf("messege: %s\n", buf);
	}
	close(clientsd);
	
	return 0;
}
