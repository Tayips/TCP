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
		perror("Creat error");
	}
	printf("Client'den mesaj bekleniyor...\n");
	struct sockaddr_in serveraddr, clientaddr;
		serveraddr.sin_addr.s_addr=INADDR_ANY;
		serveraddr.sin_family = AF_INET;
		serveraddr.sin_port = htons(5005);
		
	char buf[1024];
	
	socklen_t clientlen = sizeof(clientaddr);
	int b = bind(sock,(struct sockaddr *)&serveraddr, sizeof(serveraddr));
		if(b<0){
			perror("Bind error");
		}
	listen(sock,5);
	//Burada serverimizi clientlara açık
	
	while(1){
		int client = accept(sock,(struct sockaddr*)&clientaddr, &clientlen);
		if(client<0){
			perror("Accept Error");			
		}	
		int r = read(client, buf ,1024);
		if(r<0){
			perror("Read Error");	
		}
		printf("%s",buf);
		close(client);
	}
	return 0;
		
}			
