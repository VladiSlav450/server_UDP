#include <sys/types.h>
#include <sys/socket>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int serversd = Socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); 	
	struct sockaddr_in  adr;
	adr.sin_family = AF_INET;
	adr.sin_port = htons(6666);
	Inet_aton("192.168.10.12", &(adr.sin_addr));	
	Bind(serversd, (struct sockaddr *) adr, sizeof adr);
	
	
	return 0;
}
