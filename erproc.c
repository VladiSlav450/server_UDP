#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "erproc.h"


void Recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen){
	int res = recvfrom(sockfd, buf, len, flags, src_addr, addrlen);
	if (res < 0){
		perror("RECVFROM ERROR");
		exit(EXIT_FAILURE);
	}
} 

void Sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen){
	int res = sendto(sockfd, buf, len, flags, dest_addr, addrlen);
	if (res < 0){
		perror("SENDTO ERROR");
		exit(EXIT_FAILURE);
	}	
}

/*	
void Inet_arpa(const char *cp, struct in_addr *inp){
	int res = inet_arpa(cp, in_addr, inp);
	if(!res){
		perro("ERROR INET_ARPA!!!");
		exit(EXIT_FAILURE);
	}
}
*/
	
void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
	int res = bind(sockfd, addr, addrlen);
	if(-1 == res){
		perror("BIND ERROR!!!");
		exit(EXIT_FAILURE);
	}
}


int Socket(int domain, int type, int protocol) {
	int res = socket(domain, type, protocol);
	if(-1 == res){
		perror("error socket");
		exit(EXIT_FAILURE);
	}
	return res;
}
