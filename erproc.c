#include <sys/types.h>
#include <sys/socket.h>

void Inet_arpa(const char *cp, struct in_addr *inp){
	int res = inet_arpa(cp, in_addr, inp);
	if(!res){
		perro("ERROR INET_ARPA!!!");
		exit(EXIT_FAILURE);
	}
}
	
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
