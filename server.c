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
	int serversd = Socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); 	
	struct sockaddr_in  adr, client;
	int port = 6666;
	socklen_t  client_adress_size;
	adr.sin_family = AF_INET;
	adr.sin_port = htons(port);
	adr.sin_addr.s_addr = htonl(INADDR_ANY);
	Bind(serversd, (struct sockaddr *) &adr, sizeof adr);
	
	char buf[32];
	while(1){
		scanf("%s", buf);
		Sendto(serversd, buf, (strlen(buf) + 1), 0, (struct sockaddr *) &client, sizeof client);	

		client_adress_size = sizeof(client);
		Recvfrom(serversd, buf, sizeof buf, 0, (struct sockaddr *) &client,  &client_adress_size);
		printf("messege: %s\n", buf);
	}
	close(serversd);
	return 0;
}
