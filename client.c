#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<signal.h>
#include<wait.h>
#include<string.h>
#include<netdb.h>
int main(){
	int sock = socket(AF_INET, SOCK_STREAM,0);
	if(sock<0){
		perror("Create Error");
	}
	struct sockaddr_in serveraddr;
	struct hostent *host;
		serveraddr.sin_family=AF_INET;
		host = gethostbyname("127.0.0.1");
		serveraddr.sin_port = htons(5005);
	int c = connect(sock,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(c<0){
		perror("Connect Error");
	}
	char message[1024];
	printf("Enter your message:\n ");
	fgets(message,1024,stdin);
	printf("Your Message %s", message);
	printf("\n");
	int s = send(sock, message, strlen(message),0);
	if(s<0){
		printf("Send Error");
	}
	printf("Your message has been sent successfullys!\n");
	close(sock);
	return 0;
