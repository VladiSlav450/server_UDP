#ifndef ERPROC_h
#define ERPROC_h

void Recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);
 

void Sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen);

/*	
void Inet_arpa(const char *cp, struct in_addr *inp);
*/
	
void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	

int Socket(int domain, int type, int protocol);

#endif
