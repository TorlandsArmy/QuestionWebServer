/*
 *  [ QuestionWebserver ]
 *  by Torlands 
 *<Torlands@torlands>
 *<Torlands.LeoGomez>
 *<Torlands.AxelVA>
 *<Torlands.NegroTorlands>
 *  TorlandsArmy
 *  
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
char buf[1024];
struct sockaddr_in dire;
struct hostent *h;
int soc;


if (argc < 2)
	{
	fprintf(stderr, "----------------------\n"
					"[ questionwebserver v0.01 ]:"
					"\n----------------------\n"
					"\nUso: %s host/ip [puerto]\n\n", argv[0]);
	exit(-1);
	}


if ((h = gethostbyname(argv[1])) == NULL)
	{
	fprintf(stderr, "Error al resolver el host.\n");
	exit(-1);
	}

bzero((char *) &dire, sizeof(dire));
memcpy(&dire.sin_addr, h->h_addr, h->h_length);
dire.sin_family = AF_INET;

if (argc < 3)
	dire.sin_port = htons(80);
else
	dire.sin_port = htons(atoi(argv[2]));


if ((soc = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
	fprintf(stderr, "Error al crear el socket.\n");
	exit(-1);
	}

if ((connect(soc, (struct sockaddr *) &dire, sizeof(dire))) == -1)
	{
	fprintf(stderr, "Error al conectar con el servidor.\n");
	exit(-1);
	}	


sprintf(buf, "HEAD / HTTP/1.0\n\n");
write(soc, buf, strlen(buf));

bzero((char *) &buf, sizeof(buf));
read(soc, buf, sizeof(buf));

printf("----------------------\n"
       "[ questionwebserver v0.01 ]:\n"
	   "----------------------\n\n%s", buf);


return(0);
}

/* 
*Torlands.LeoGomez
*Torlands.AxelVA
*Torlands.NegroTorlands
 */
